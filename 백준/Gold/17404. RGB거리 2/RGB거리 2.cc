#include <iostream>
using namespace std;

int N;
int DP[1000][3];
int Arr[1000][3];

int Answer = 2147483647;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Arr[i][j];
		}
	}

	int n = 0;
	while (n < 3)
	{
		for (int c = 0; c < 3; c++) {
			if (c != n) DP[0][c] = 1001;
			else DP[0][c] = Arr[0][c];
		}

		for (int i = 1; i < N; i++) {
			for (int c = 0; c < 3; c++) {
				DP[i][c] = min(DP[i - 1][(c + 1) % 3], DP[i - 1][(c + 2) % 3]) + Arr[i][c];
			}
		}

		for (int c = 0; c < 3; c++) {
			if (c == n) continue;

			Answer = min(Answer, DP[N - 1][c]);
		}

		for (int i = 0; i < N; i++) {
			for (int c = 0; c < 3; c++) {
				DP[i][c] = 0;
			}
		}

		n++;
	}

	cout << Answer;
}