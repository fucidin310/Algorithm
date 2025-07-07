#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxPQ;
priority_queue<int, vector<int>, greater<int>> minPQ;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	while (N--)
	{
		int input;
		cin >> input;

		if (maxPQ.empty() || maxPQ.size() == minPQ.size())
		{
			maxPQ.push(input);
		}
		else
		{
			minPQ.push(input);
		}

		if (!maxPQ.empty() && !minPQ.empty() && maxPQ.top() > minPQ.top())
		{
			int maxValue = maxPQ.top();
			int minValue = minPQ.top();

			maxPQ.pop();
			minPQ.pop();

			maxPQ.push(minValue);
			minPQ.push(maxValue);
		}

		cout << maxPQ.top() << '\n';
	}
}
