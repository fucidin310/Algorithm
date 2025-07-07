#include <iostream>
#include <stack>
using namespace std;

struct Matrix
{
	long long a, b, c, d;

	Matrix(long _a, long _b, long _c, long _d)
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
};

int divideNum = 1000000;

Matrix AddMatrix(Matrix& input)
{
	return Matrix((input.a + input.c) % divideNum, (input.b + input.d) % divideNum, (input.a) % divideNum, (input.b) % divideNum);
}

Matrix MultMatrix(Matrix& input)
{
	return Matrix((input.a * input.a + input.b * input.c) % divideNum, (input.a * input.b + input.b * input.d) % divideNum, (input.a * input.c + input.c * input.d) % divideNum, (input.b * input.c + input.d * input.d) % divideNum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long N;
	cin >> N;

	// 더하기 = true, 곱하기 = false
	stack<bool> MyStack;

	while (N != 1)
	{
		if (N % 2 == 0)
		{
			N /= 2;
			MyStack.push(false);
		}
		else
		{
			N -= 1;
			MyStack.push(true);
		}
	}

	Matrix output = Matrix(1, 1, 1, 0);
	while (!MyStack.empty())
	{
		if (MyStack.top())
		{
			output = AddMatrix(output);
		}
		else
		{
			output = MultMatrix(output);
		}

		MyStack.pop();
	}

	cout << output.c;
}
