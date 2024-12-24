#include <iostream>
using namespace std;

int N, M;
int Memorys[100];
int Values[100];
int DP[10001][100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Memorys[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> Values[i];
	}

	for (int v = 0; v <= 10000; v++) {
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				if (Values[0] <= v) {
					DP[v][0] = Memorys[0];
				}
			}
			else {
				if (Values[i] <= v) {
					DP[v][i] = max(DP[v][i - 1], DP[v - Values[i]][i - 1] + Memorys[i]);
				}
				else {
					DP[v][i] = DP[v][i - 1];
				}
			}

			if (DP[v][i] >= M) {
				cout << v;
				exit(0);
			}
		}
	}
}