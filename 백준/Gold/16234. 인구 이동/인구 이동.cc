#include <iostream>
#include <vector>
using namespace std;

int N, L, R;
int A[51][51];
int UnionA[51][51];
vector<pair<int, int>> UnionInfo;
int Answer;
bool flag = true;

void Union(int r1, int c1, int r2, int c2);
int Find(int r, int c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	UnionInfo.resize(N * N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	while (flag)
	{
		flag = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				UnionA[i][j] = N * (i - 1) + j;
				UnionInfo[N * (i - 1) + j] = make_pair(1, A[i][j]);
			}
		}

		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (abs(A[i][j] - A[i][j + 1]) <= R && abs(A[i][j] - A[i][j + 1]) >= L) {
					flag = true;
					Union(i, j, i, j + 1);
				}
				if (abs(A[i][j] - A[i + 1][j]) <= R && abs(A[i][j] - A[i + 1][j]) >= L) {
					flag = true;
					Union(i, j, i + 1, j);
				}
			}
		}
		for (int i = 1; i < N; i++) {
			if (abs(A[i][N] - A[i + 1][N]) <= R && abs(A[i][N] - A[i + 1][N]) >= L) {
				flag = true;
				Union(i, N, i + 1, N);
			}
			if (abs(A[N][i] - A[N][i + 1]) <= R && abs(A[N][i] - A[N][i + 1]) >= L) {
				flag = true;
				Union(N, i, N, i + 1);
			}
		}
		if (!flag)
			break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int temp = Find(i, j);
				if (UnionInfo[temp].second == 0)
					continue;
				A[i][j] = UnionInfo[temp].second / UnionInfo[temp].first;
			}
		}
		Answer++;
	}
	std::cout << Answer;
}

void Union(int r1, int c1, int r2, int c2) {
	int temp1 = Find(r1, c1);
	int temp2 = Find(r2, c2);
	if (temp1 == temp2)
		return;

	UnionInfo[temp1] = make_pair(UnionInfo[temp1].first + UnionInfo[temp2].first, UnionInfo[temp1].second + UnionInfo[temp2].second);
	UnionA[(temp2 - 1) / N + 1][(temp2 - 1) % N + 1] = temp1;
}

int Find(int r, int c) {
	if (N * (r - 1) + c == UnionA[r][c])
		return UnionA[r][c];
	else {
		return Find((UnionA[r][c] - 1) / N + 1, (UnionA[r][c] - 1) % N + 1);
	}
}