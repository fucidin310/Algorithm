#include <iostream>
#include <vector>
using namespace std;

int treeSize = 1;
vector<int> Tree;
vector<int> Value;

void ChangeValue(int index, int value)
{
	index--;

	Value[index] = value;

	index += treeSize / 2;
	index /= 2;

	while (index > 0)
	{
		int ValueL = Value[Tree[index * 2]];
		int ValueR = Value[Tree[index * 2 + 1]];
		if (ValueL <= ValueR)
		{
			Tree[index] = Tree[index * 2];
		}
		else
		{
			Tree[index] = Tree[index * 2 + 1];
		}

		index /= 2;
	}
}

void PrintMinIndex(int start, int end)
{
	start += treeSize / 2 - 1;
	end += treeSize / 2 - 1;

	int minIndex = Tree[start];
	int minValue = Value[Tree[start]];

	while (start <= end)
	{
		if (start == end)
		{
			if (minValue > Value[Tree[start]])
			{
				minIndex = Tree[start];
				minValue = Value[Tree[start]];
			}
			else if (minValue == Value[Tree[start]])
			{
				if (Tree[start] < minIndex)
				{
					minIndex = Tree[start];
				}
			}

			break;
		}

		if (start % 2 == 1)
		{
			if (minValue > Value[Tree[start]])
			{
				minIndex = Tree[start];
				minValue = Value[Tree[start]];
			}
			else if (minValue == Value[Tree[start]])
			{
				if (Tree[start] < minIndex)
				{
					minIndex = Tree[start];
				}
			}

			start = (start + 1) / 2;
		}
		else
		{
			start = start / 2;
		}

		if (end % 2 == 0)
		{
			if (minValue > Value[Tree[end]])
			{
				minIndex = Tree[end];
				minValue = Value[Tree[end]];
			}
			else if (minValue == Value[Tree[end]])
			{
				if (Tree[end] < minIndex)
				{
					minIndex = Tree[end];
				}
			}

			end = (end - 1) / 2;
		}
		else
		{
			end = end / 2;
		}
	}

	cout << minIndex + 1 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	while (treeSize < N)
	{
		treeSize *= 2;
	}
	treeSize *= 2;

	Tree.resize(treeSize, 0);
	Value.resize(treeSize / 2, 2147483647);

	for (int i = 0; i < N; i++)
	{
		cin >> Value[i];
	}

	for (int i = 0; i < treeSize / 2; i++)
	{
		Tree[treeSize / 2 + i] = i;
	}

	for (int i = treeSize / 2 - 1; i > 0; i--)
	{
		int ValueA = Value[Tree[i * 2]];
		int ValueB = Value[Tree[i * 2 + 1]];

		if(ValueA <= ValueB) Tree[i] = Tree[i * 2];
		else Tree[i] = Tree[i * 2 + 1];
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) ChangeValue(b, c);
		else PrintMinIndex(b, c);
	}
}
