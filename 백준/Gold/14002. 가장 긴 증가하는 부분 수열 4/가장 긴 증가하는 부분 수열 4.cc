#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> Arr;
	vector<int> DP;

	Arr.resize(N);
	DP.resize(N);

	cin >> Arr[0];
	DP[0] = 1;

	int max_length = 1;

	for (int i = 1; i < N; i++)
	{
		cin >> Arr[i];
		int tmp_length = 0;

		for (int j = 0; j < i; j++)
		{
			if (Arr[j] < Arr[i]) tmp_length = max(tmp_length, DP[j]);
		}

		DP[i] = tmp_length + 1;
		max_length = max(max_length, DP[i]);
	}

	cout << max_length << '\n';

	stack<int> outputStack;
	int curIndex = Arr.size() - 1;

	while (curIndex >= 0)
	{
		if (DP[curIndex] == max_length)
		{
			outputStack.push(Arr[curIndex]);
			max_length--;
		}

		curIndex--;
	}

	while (!outputStack.empty())
	{
		cout << outputStack.top() << ' ';
		outputStack.pop();
	}
}
