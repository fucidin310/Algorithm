#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;

int N, M;
vector<vector<edge>> edges;
int Distance[1001];
bool visited[1001];
priority_queue<edge, vector<edge>, greater<edge>> pq;
int PreCity[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Distance[i] = 2147483647 - 100001;
	}

	edges.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int S, E, W;
		cin >> S >> E >> W;
		edges[S].push_back(make_pair(E, W));
	}

	int S, E;
	cin >> S >> E;
	pq.push(make_pair(0, S));
	Distance[S] = 0;
	while (!pq.empty())
	{
		int nowNode = pq.top().second;
		int nowDistance = pq.top().first;
		pq.pop();
		if (visited[nowNode] != 0)
			continue;
		visited[nowNode] = true;

		for (int i = 0; i < edges[nowNode].size(); i++) {
			int nextNode = edges[nowNode][i].first;
			int nextWeight = edges[nowNode][i].second;
			if (Distance[nextNode] > nextWeight + Distance[nowNode]) {
				Distance[nextNode] = nextWeight + Distance[nowNode];
				pq.push(make_pair(Distance[nextNode], nextNode));
				PreCity[nextNode] = nowNode;
			}
		}
	}

	cout << Distance[E] << "\n";
	int nowNode = E;
	vector<int> Answer;
	while (nowNode != S)
	{
		Answer.push_back(nowNode);
		nowNode = PreCity[nowNode];
	}
	Answer.push_back(S);
	cout << Answer.size() << "\n";
	for (int i = Answer.size() - 1; i >= 0; i--) {
		cout << Answer[i] << " ";
	}
}