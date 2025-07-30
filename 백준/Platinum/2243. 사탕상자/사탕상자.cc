#include <iostream>
using namespace std;

const int Max = 2097152;
int Tree[Max] = {0};

void PushCandy(int value, int num)
{
	int curIndex = Max / 2 + value;

	while (curIndex > 0)
	{
		Tree[curIndex] += num;
		curIndex /= 2;
	}
}

void PopCandy(int value)
{
	int curIndex = 1;

	while (curIndex < Max / 2)
	{
		if (Tree[curIndex * 2] >= value)
		{
			curIndex *= 2;
		}
		else
		{
			value -= Tree[curIndex * 2];
			curIndex = curIndex * 2 + 1;
		}
	}

	int outputValue = curIndex - Max / 2;
	cout << outputValue << '\n';
	PushCandy(outputValue, -1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		int A, B, C;
		cin >> A;

		if (A == 1)
		{
			cin >> B;

			PopCandy(B);
		}
		else
		{
			cin >> B >> C;

			PushCandy(B, C);
		}
	}
}
