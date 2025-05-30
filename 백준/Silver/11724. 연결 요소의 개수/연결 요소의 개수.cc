#include <iostream>
#include <vector>
#include <set>
using namespace std;

void Union(int A, int B);
int Find(int Num);
vector<int> UnionList;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	UnionList.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		UnionList[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}

	set<int> tmpSet;

	for (int i = 1; i <= N; i++)
	{
		int tmpInt = Find(i);
		tmpSet.insert(tmpInt);
	}
	
	cout << tmpSet.size();
}

void Union(int A, int B)
{
	int FindA = Find(A);
	int FindB = Find(B);

	if (FindA == FindB) return;

	UnionList[FindB] = FindA;
}

int Find(int Num)
{
	if (UnionList[Num] == Num) return Num;

	return UnionList[Num] = Find(UnionList[Num]);
}
