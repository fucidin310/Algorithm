#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> values;
	queue<int> MyQueue;
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	if (S == G)
	{
		cout << 0;
		return 0;
	}

	values.resize(F + 1, 2147483647);
	values[S] = 0;
	MyQueue.push(S);

	while (!MyQueue.empty())
	{
		int curPos = MyQueue.front();
		int curValue = values[curPos];
		MyQueue.pop();

		int upPos = curPos + U;
		int downPos = curPos - D;

		if (upPos <= F && values[upPos] > curValue + 1)
		{
			MyQueue.push(upPos);
			values[upPos] = curValue + 1;

			if (upPos == G)
			{
				cout << values[upPos];
				return 0;
			}
		}

		if (downPos > 0 && values[downPos] > curValue + 1)
		{
			MyQueue.push(downPos);
			values[downPos] = curValue + 1;

			if (downPos == G)
			{
				cout << values[downPos];
				return 0;
			}
		}
	}

	cout << "use the stairs";
}
