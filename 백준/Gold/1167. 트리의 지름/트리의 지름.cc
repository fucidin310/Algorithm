#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V;
vector<vector<pair<int, int>>> A;
vector<int> Distance;
queue<int> MyQueue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	A.resize(V + 1);
	Distance.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		int S, E;
		cin >> S >> E;
		while (E != -1)
		{
			int Value;
			cin >> Value;
			A[S].push_back(make_pair(E, Value));

			cin >> E;
		}
	}

	int StartNode = 1;
	fill(Distance.begin(), Distance.end(), 2147483647);
	Distance[StartNode] = 0;
	MyQueue.push(StartNode);
	while (!MyQueue.empty())
	{
		int NowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < A[NowNode].size(); i++) {
			if (Distance[A[NowNode][i].first] > Distance[NowNode] + A[NowNode][i].second) {
				Distance[A[NowNode][i].first] = Distance[NowNode] + A[NowNode][i].second;
				MyQueue.push(A[NowNode][i].first);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (Distance[StartNode] < Distance[i]) {
			StartNode = i;
		}
	}

	fill(Distance.begin(), Distance.end(), 2147483647 - 100001);
	Distance[StartNode] = 0;
	MyQueue.push(StartNode);
	while (!MyQueue.empty())
	{
		int NowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < A[NowNode].size(); i++) {
			if (Distance[A[NowNode][i].first] > Distance[NowNode] + A[NowNode][i].second) {
				Distance[A[NowNode][i].first] = Distance[NowNode] + A[NowNode][i].second;
				MyQueue.push(A[NowNode][i].first);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (Distance[StartNode] < Distance[i]) {
			StartNode = i;
		}
	}

	cout << Distance[StartNode];
}