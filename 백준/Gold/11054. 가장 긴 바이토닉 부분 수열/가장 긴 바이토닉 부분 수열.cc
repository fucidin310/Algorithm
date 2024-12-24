#include <iostream>
using namespace std;

int S[1000];
int DP[2][1000];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	for (int i = 0; i < N; i++) {
		DP[0][i] = 1;
		for (int j = 0; j < i; j++) {
			if (S[j] < S[i]) {
				DP[0][i] = max(DP[0][i], DP[0][j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		DP[1][i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (S[j] < S[i]) {
				DP[1][i] = max(DP[1][i], DP[1][j] + 1);
			}
		}
	}

	int Answer = 0;
	for (int i = 0; i < N; i++) {
		Answer = max(Answer, DP[0][i] + DP[1][i] - 1);
	}
	cout << Answer;
}