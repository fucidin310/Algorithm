#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> MyQueue;

	int input;
	int output = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		MyQueue.push(input);
	}
	
	while (MyQueue.size() > 1)
	{
		int a = MyQueue.top();
		MyQueue.pop();
		int b = MyQueue.top();
		MyQueue.pop();

		output += a + b;
		MyQueue.push(a + b);
	}

	cout << output;
}
