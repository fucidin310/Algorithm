#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R, Q;
vector<int> Input[100001];
vector<int> Tree[100001];
bool visited[100001];
int AnswerList[100001];
queue<int> myQueue;

int PrintAnswer(int node) {
	if (AnswerList[node] != 0) return AnswerList[node];
	int output = 0;

	for (int i = 0; i < Tree[node].size(); i++) {
		output += PrintAnswer(Tree[node][i]);
	}

	return AnswerList[node] = output + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		int s, e;
		cin >> s >> e;

		Input[s].push_back(e);
		Input[e].push_back(s);
	}
	myQueue.push(R);

	while (!myQueue.empty())
	{
		int Node = myQueue.front();
		visited[Node] = true;
		myQueue.pop();

		for (int node : Input[Node]) {
			if (!visited[node]) {
				visited[node];
				myQueue.push(node);
				Tree[Node].push_back(node);
			}
		}
	}

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;

		cout << PrintAnswer(q) << "\n";
	}
}
