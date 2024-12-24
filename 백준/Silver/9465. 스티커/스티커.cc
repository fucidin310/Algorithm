#include <iostream>
using namespace std;

int T, n;
int DP[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T > 0)
	{
		T--;

		//입력
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> DP[i][j];
			}
		}

		int Answer = max(DP[0][1], DP[1][1]);
		//DP
		for (int j = 2; j <= n; j++) {
			for (int i = 0; i < 2; i++) {
				DP[i][j] += max(DP[(i + 1) % 2][j - 1], max(DP[(i + 1) % 2][j - 2], DP[i][j - 2]));
				Answer = max(Answer, DP[i][j]);
			}
		}

		cout << Answer << '\n';

		//초기화
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				DP[i][j] = 0;
			}
		}
	}
}