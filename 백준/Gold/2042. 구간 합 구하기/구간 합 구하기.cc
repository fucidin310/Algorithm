#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> tree;
int nodeStartIndex;

void ChangeNum(int index, long long Value)
{
	index = nodeStartIndex + index - 1;

	long long AddValue = Value - tree[index];

	while (index > 0)
	{
		tree[index] += AddValue;

		index /= 2;
	}
}

void PrintSum(int start, int end)
{
	long long output = 0;

	int start_index = start + nodeStartIndex - 1;
	int end_index = end + nodeStartIndex - 1;

	while (start_index <= end_index)
	{
		if (start_index == end_index)
		{
			output += tree[start_index];
			break;
		}

		if (start_index % 2 == 1)
		{
			output += tree[start_index];
			start_index = (start_index / 2) + 1;
		}
		else
		{
			start_index = start_index / 2;
		}

		if (end_index % 2 == 0)
		{
			output += tree[end_index];
			end_index = (end_index / 2) - 1;
		}
		else
		{
			end_index = end_index / 2;
		}
	}

	cout << output << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, C, P;
	cin >> N >> C >> P;

	int treeHeight = 1;
	int Length = 2;

	while (Length < N)
	{
		Length *= 2;
		treeHeight++;
	}
	Length *= 2;
	treeHeight++;

	int treeSize = int(pow(2, treeHeight));
	nodeStartIndex = treeSize / 2;
	tree.resize(treeSize);

	for (int i = 0; i < N; i++)
	{
		cin >> tree[nodeStartIndex + i];
	}

	for (int i = treeSize - 1; i > 0; i--)
	{
		tree[i / 2] += tree[i];
	}

	for (int i = 0; i < C + P; i++)
	{
		long long a, s, e;
		cin >> a >> s >> e;

		if (a == 1) ChangeNum(s, e);
		else PrintSum(s, e);
	}
}
