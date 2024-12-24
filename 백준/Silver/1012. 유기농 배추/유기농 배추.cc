#include <iostream>
#include <vector>
using namespace std;

int A[52][52];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int T;
int N, M, K;
int Answer;
vector<int> UnionList;

void MoveBug(int x, int y);

int main() {
	cin >> T;
	while (T > 0)
	{
		T--;
		Answer = 0;

		cin >> M >> N >> K;
		//배추심기
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			A[x + 1][y + 1] = -1;
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (A[i][j] == -1) {
					Answer++;
					A[i][j] = Answer;
					MoveBug(i, j);
				}
			}
		}
		cout << Answer << '\n';
	}
}

void MoveBug(int x, int y) {
	for (int k = 0; k < 4; k++) {
		if (A[x + dx[k]][y + dy[k]] == -1) {
			A[x + dx[k]][y + dy[k]] = A[x][y];
			MoveBug(x + dx[k], y + dy[k]);
		}
	}
}