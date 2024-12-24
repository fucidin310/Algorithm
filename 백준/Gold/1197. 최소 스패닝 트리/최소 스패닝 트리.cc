#include <iostream>
#include <queue>
using namespace std;

typedef struct edge
{
	int start;
	int end;
	int weight;

	bool operator > (const edge& temp) const {
		return weight > temp.weight;
	}
} edge;

int V, E;
int A, B, C;
int unionA[10001];

priority_queue<edge, vector<edge>, greater<edge>> MyQueue;

void Union(int index1, int index2);
int Find(int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i <= V; i++) {
		unionA[i] = i;
	}
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		MyQueue.push(edge{ A, B, C });
	}

	int Answer = 0;
	int connectNum = 0;

	while (connectNum < V - 1)
	{
		edge nowEdge = MyQueue.top();
		MyQueue.pop();

		if (Find(nowEdge.start) != Find(nowEdge.end)) {
			Union(nowEdge.start, nowEdge.end);
			Answer += nowEdge.weight;
			connectNum++;
		}
	}

	cout << Answer;
}

void Union(int index1, int index2)
{
	index1 = Find(index1);
	index2 = Find(index2);

	if (index1 != index2) {
		unionA[index2] = index1;
	}
}

int Find(int index)
{
	if (index == unionA[index])
		return index;
	else {
		return unionA[index] = Find(unionA[index]);
	}
}
