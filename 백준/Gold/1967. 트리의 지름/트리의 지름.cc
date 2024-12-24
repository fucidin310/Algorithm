#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int s, e, w;
vector<vector<pair<int, int>>> edges;
vector<int> Distance;
queue<int> MyQueue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	edges.resize(N + 1);
	Distance.resize(N + 1, 2147483647 - 101);
	for (int i = 1; i < N; i++) {
		cin >> s >> e >> w;
		edges[s].push_back(make_pair(w, e));
		edges[e].push_back(make_pair(w, s));
	}
	Distance[1] = 0;
	MyQueue.push(1);
	while (!MyQueue.empty())
	{
		int nowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < edges[nowNode].size(); i++) {
			int nextNode = edges[nowNode][i].second;
			int nextWeight = edges[nowNode][i].first;
			if (Distance[nextNode] > Distance[nowNode] + nextWeight) {
				Distance[nextNode] = Distance[nowNode] + nextWeight;
				MyQueue.push(nextNode);
			}
		}
	}
	int maxDistanceNode = 1;
	for (int i = 1; i < Distance.size(); i++) {
		if (Distance[maxDistanceNode] < Distance[i]) {
			Distance[maxDistanceNode] = Distance[i];
			maxDistanceNode = i;
		}
	}

	fill(Distance.begin(), Distance.end(), 2147483647 - 101);
	Distance[maxDistanceNode] = 0;
	MyQueue.push(maxDistanceNode);
	while (!MyQueue.empty())
	{
		int nowNode = MyQueue.front();
		MyQueue.pop();

		for (int i = 0; i < edges[nowNode].size(); i++) {
			int nextNode = edges[nowNode][i].second;
			int nextWeight = edges[nowNode][i].first;
			if (Distance[nextNode] > Distance[nowNode] + nextWeight) {
				Distance[nextNode] = Distance[nowNode] + nextWeight;
				MyQueue.push(nextNode);
			}
		}
	}
	for (int i = 1; i < Distance.size(); i++) {
		if (Distance[maxDistanceNode] < Distance[i]) {
			Distance[maxDistanceNode] = Distance[i];
		}
	}

	cout << Distance[maxDistanceNode];
}