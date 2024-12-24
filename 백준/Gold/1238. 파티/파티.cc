#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> GoParty;
vector<vector<pair<int, int>>> ComeBack;
vector<int> DistanceGoParty;
vector<int> DistanceComeBack;
queue<int> MyQueue;
int Answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;
	GoParty.resize(N + 1);
	ComeBack.resize(N + 1);
	DistanceGoParty.resize(N + 1, 2147483647 - 101);
	DistanceComeBack.resize(N + 1, 2147483647 - 101);
	for (int i = 0; i < M; i++) {
		int S, E, V;
		cin >> S >> E >> V;
		ComeBack[S].push_back(make_pair(E, V));
		GoParty[E].push_back(make_pair(S, V));
	}

	MyQueue.push(X);
	DistanceGoParty[X] = 0;
	while (!MyQueue.empty())
	{
		int NowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < GoParty[NowNode].size(); i++) {
			if (DistanceGoParty[GoParty[NowNode][i].first] > DistanceGoParty[NowNode] + GoParty[NowNode][i].second) {
				DistanceGoParty[GoParty[NowNode][i].first] = DistanceGoParty[NowNode] + GoParty[NowNode][i].second;
				MyQueue.push(GoParty[NowNode][i].first);
			}
		}
	}

	MyQueue.push(X);
	DistanceComeBack[X] = 0;
	while (!MyQueue.empty())
	{
		int NowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < ComeBack[NowNode].size(); i++) {
			if (DistanceComeBack[ComeBack[NowNode][i].first] > DistanceComeBack[NowNode] + ComeBack[NowNode][i].second) {
				DistanceComeBack[ComeBack[NowNode][i].first] = DistanceComeBack[NowNode] + ComeBack[NowNode][i].second;
				MyQueue.push(ComeBack[NowNode][i].first);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (Answer < DistanceGoParty[i] + DistanceComeBack[i]) {
			Answer = DistanceGoParty[i] + DistanceComeBack[i];
		}
	}

	cout << Answer;
}