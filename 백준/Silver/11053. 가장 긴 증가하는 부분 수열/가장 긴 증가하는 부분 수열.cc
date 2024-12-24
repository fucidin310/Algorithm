#include <iostream>
using namespace std;

int N;
int A[1000];
int DP[1000];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	fill(DP, DP + N, 1);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (A[i] < A[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, DP[i]);
	}
	cout << ans;
}