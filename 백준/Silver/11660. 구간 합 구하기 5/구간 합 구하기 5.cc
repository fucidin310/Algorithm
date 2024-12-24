#include <iostream>
using namespace std;

int N, M, Input;
int A[1024][1024];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> Input;
			if (x == 0 && y == 0)
				A[0][0] = Input;
			else if (x == 0)
				A[0][y] = A[0][y - 1] + Input;
			else if (y == 0)
				A[x][0] = A[x - 1][0] + Input;
			else
				A[x][y] = A[x - 1][y] + A[x][y - 1] - A[x - 1][y - 1] + Input;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		if (x1 == 1 && y1 == 1)
			cout << A[x2 - 1][y2 - 1] << "\n";
		else if (x1 == 1)
			cout << A[x2 - 1][y2 - 1] - A[x2 - 1][y1 - 2] << "\n";
		else if (y1 == 1)
			cout << A[x2 - 1][y2 - 1] - A[x1 - 2][y2 - 1] << "\n";
		else
			cout << A[x2 - 1][y2 - 1] - A[x2 - 1][y1 - 2] - A[x1 - 2][y2 - 1] + A[x1 - 2][y1 - 2] << "\n";
	}
}
