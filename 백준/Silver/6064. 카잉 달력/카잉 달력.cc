#include <iostream>
#include <vector>
using namespace std;

int T, M, N, x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> M >> N >> x >> y;

		int A, B;

		if (M > N) {
			A = M;
			B = N;
		}
		else {
			A = N;
			B = M;
		}

		int GCFac;
		int LCMul;

		while (true)
		{
			int temp;
			temp = A % B;

			if (temp == 0) {
				GCFac = B;
				LCMul = M * N / GCFac;
				break;
			}

			A = B;
			B = temp;
		}
		int curYear = x;
		int curX = x;
		int curY = x;
		bool hasAnswer = false;

		while (curYear <= LCMul)
		{

			if (curY > N) {
				curY = (curY - 1) % N + 1;

			}

			if (curX == x && curY == y) {
				cout << curYear << '\n';
				hasAnswer = true;
				break;
			}

			curYear += M;
			curY += M;

		}

		if(!hasAnswer)
			cout << "-1\n";
	}
}