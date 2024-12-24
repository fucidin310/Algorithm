#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, K, W;
int D[1001];
int B[1001];
vector<int> A[1001];
queue<int> MyQueue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T > 0)
	{
		T--;

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> D[i];
		}

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;

			A[Y].push_back(X);
		}

		cin >> W;

		int Answer = 0;
		MyQueue.push(W);
		B[W] = D[W];
		while (!MyQueue.empty())
		{
			int nowBuilding = MyQueue.front();
			if (Answer < B[nowBuilding])
				Answer = B[nowBuilding];
			MyQueue.pop();

			for (int i = 0; i < A[nowBuilding].size(); i++) {
				if (B[A[nowBuilding][i]] < D[A[nowBuilding][i]] + B[nowBuilding]) {
					B[A[nowBuilding][i]] = D[A[nowBuilding][i]] + B[nowBuilding];
					MyQueue.push(A[nowBuilding][i]);
				}
			}
		}

		cout << Answer << '\n';

		fill(&B[1], &B[N] + 1, 0);
		for (int i = 1; i <= N; i++) {
			A[i].clear();
		}
	}
}