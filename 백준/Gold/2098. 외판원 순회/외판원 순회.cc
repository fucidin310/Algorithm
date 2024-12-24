#include <iostream>
#include <queue>
using namespace std;

int N;
int Dp[16][65536];
int Distance[16][16];

queue<pair<int, int>> MyQueue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Distance[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		if (Distance[0][i] > 0) {
			Dp[i][1 << i | 1 << 0] = Distance[0][i];
			MyQueue.push(make_pair(i, 1 << i | 1 << 0));
		}
	}

	while (!MyQueue.empty())
	{
		int nowCity = MyQueue.front().first;
		int nowVisited = MyQueue.front().second;
		MyQueue.pop();

		for (int i = 0; i < N; i++) {
			if (Distance[nowCity][i] == 0)
				continue;

			if (nowVisited & 1 << i)
				continue;

			if (Dp[i][nowVisited | 1 << i] == 0) {
				MyQueue.push(make_pair(i, nowVisited | 1 << i));
				Dp[i][nowVisited | 1 << i] = Dp[nowCity][nowVisited] + Distance[nowCity][i];
			}
			else if (Dp[nowCity][nowVisited] + Distance[nowCity][i] < Dp[i][nowVisited | 1 << i]) {
				Dp[i][nowVisited | 1 << i] = Dp[nowCity][nowVisited] + Distance[nowCity][i];
			}
		}
	}

	int Answer = 2147483647;
	for (int i = 0; i < N; i++) {
		if(Distance[i][0] > 0 && Dp[i][(1 << N) - 1] > 0)
			Answer = min(Answer, Dp[i][(1 << N) - 1] + Distance[i][0]);
	}
	cout << Answer;
}