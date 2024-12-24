#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, E, v1, v2;
vector<vector<pair<int, int>>> A;
int Dijkstra(int startNode, int endNode);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	A.resize(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		A[a].push_back(make_pair(b, c));
		A[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	int course1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
	int course2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);

	if (course1 < 0 && course2 < 0) {
		cout << "-1";
	}
	else if (course1 < 0) {
		cout << course2;
	}
	else if (course2 < 0) {
		cout << course1;
	}
	else {
		cout << min(course1, course2);
	}
}

int Dijkstra(int startNode, int endNode)
{
	queue<int> MyQueue;
	vector<int> Distance;
	Distance.resize(N + 1, 2147483647 - 1001);
	Distance[startNode] = 0;
	MyQueue.push(startNode);

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

	if (Distance[endNode] == 2147483647 - 1001) {
		return (-2147483647 - 1) / 3;
	}
	else {
		return Distance[endNode];
	}
}
