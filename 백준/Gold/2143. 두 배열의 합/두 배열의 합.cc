#include <iostream>
#include <map>
using namespace std;

int T, n, m;
map<int, int> MyMap;
int SumA[1000];
int SumB[1000];
long long Answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	cin >> n;
	cin >> SumA[0];
	MyMap[SumA[0]]++;

	for (int i = 1; i < n; i++) {
		cin >> SumA[i];
		SumA[i] += SumA[i - 1];
		MyMap[SumA[i]]++;

		for (int j = 0; j < i; j++) {
			MyMap[SumA[i] - SumA[j]]++;
		}
	}

	cin >> m;
	cin >> SumB[0];
	Answer += MyMap[T - SumB[0]];

	for (int i = 1; i < m; i++) {
		cin >> SumB[i];
		SumB[i] += SumB[i - 1];
		Answer += MyMap[T - SumB[i]];

		for (int j = 0; j < i; j++) {
			Answer += MyMap[T - (SumB[i] - SumB[j])];
		}
	}

	cout << Answer;
}