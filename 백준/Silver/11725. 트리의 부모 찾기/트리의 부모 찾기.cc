#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> answer;
vector<bool> visited;
vector<vector<int>> edges;

queue<int> MyQueue;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	answer.resize(N + 1, 0);
	visited.resize(N + 1, false);
	edges.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	MyQueue.push(1);
	visited[1] = true;

	while (!MyQueue.empty())
	{
		int curIndex = MyQueue.front();
		MyQueue.pop();

		for (int nextIndex : edges[curIndex])
		{
			if (visited[nextIndex]) continue;

			visited[nextIndex] = true;
			answer[nextIndex] = curIndex;

			MyQueue.push(nextIndex);
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << answer[i] << '\n';
	}
}
