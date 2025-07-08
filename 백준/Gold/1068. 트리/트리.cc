#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<vector<int>> edges;
	queue<int> MyQueue;

	int N, D;
	cin >> N;

	edges.resize(N);

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		if (input == -1) MyQueue.push(i);
		else edges[input].push_back(i);
	}

	cin >> D;
	if (D == MyQueue.front()) MyQueue.pop();

	int answer = 0;
	while (!MyQueue.empty())
	{
		int curIndex = MyQueue.front();
		MyQueue.pop();

		int leafCnt = 0;
		for (int nextIndex : edges[curIndex])
		{
			if (nextIndex == D) continue;

			leafCnt++;
			MyQueue.push(nextIndex);
		}

		if (leafCnt == 0) answer++;
	}

	cout << answer;
}
