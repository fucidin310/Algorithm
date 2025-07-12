#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long N, answer;
	vector<long long> inputs;
	vector<long long> arr;
	stack<long long> MyStack;

	while (true)
	{
		cin >> N;
		if (N == 0) break;

		answer = 0;

		inputs.resize(N);
		arr.resize(N);

		for (int i = 0; i < N; i++)
		{
			cin >> inputs[i];
			arr[i] = inputs[i];
		}

		for (int i = 0; i < N; i++)
		{
			while (!MyStack.empty() && inputs[MyStack.top()] > inputs[i])
			{
				arr[MyStack.top()] += inputs[MyStack.top()] * (i - MyStack.top() - 1);
				answer = max(answer, arr[MyStack.top()]);
				MyStack.pop();
			}

			if(MyStack.empty()) arr[i] += inputs[i] * i;
			else  arr[i] += inputs[i] * (i - MyStack.top() - 1);

			MyStack.push(i);
		}

		while (!MyStack.empty())
		{
			arr[MyStack.top()] += inputs[MyStack.top()] * (N - MyStack.top() - 1);
			answer = max(answer, arr[MyStack.top()]);
			MyStack.pop();
		}

		cout << answer << '\n';
	}	
}
