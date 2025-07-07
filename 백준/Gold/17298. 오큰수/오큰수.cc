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

	vector<int> inputs(N);
	vector<int> outputs(N, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> inputs[i];
	}

	stack<int> MyStack;

	for (int i = 0; i < N; i++)
	{
		while (!MyStack.empty() && inputs[MyStack.top()] < inputs[i])
		{
			outputs[MyStack.top()] = inputs[i];
			MyStack.pop();
		}

		MyStack.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << outputs[i];
		if (i != N - 1) cout << ' ';
	}
}
