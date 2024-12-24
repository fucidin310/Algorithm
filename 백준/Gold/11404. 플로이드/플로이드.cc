#include <iostream>
using namespace std;

int map[101][101];
int N, M;
int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = 2147483647 / 2;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				if (s == e || s == k || k == e)
					continue;

				map[s][e] = min(map[s][e], map[s][k] + map[k][e]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(map[i][j] == 2147483647 / 2)
				cout << "0 ";
			else
				cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}