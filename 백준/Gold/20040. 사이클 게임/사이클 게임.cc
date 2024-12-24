#include <iostream>
using namespace std;

int n, m;
bool Visited[500000];
int UnionArr[500000];
int Answer = 0;

int Find(int Index);
void Union(int FirstIndex, int SecondIndex);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		UnionArr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		if (Answer != 0) continue;

		Visited[s] = true;
		if (Visited[e] && Find(s) == Find(e)) {
			Answer = i + 1;
		}
		Union(s, e);
		Visited[e] = true;
	}

	cout << Answer;
}

int Find(int Index)
{
	if (UnionArr[Index] == Index) return Index;

	return UnionArr[Index] = Find(UnionArr[Index]);
}

void Union(int FirstIndex, int SecondIndex)
{
	UnionArr[Find(FirstIndex)] = UnionArr[Find(SecondIndex)];
}