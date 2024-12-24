#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int> Info;
priority_queue<Info, vector<Info>, greater<Info>> MyQueue;

int N, M;
int Map[1002][1002];
int DistanceToStart[1002][1002];
int DistanceToEnd[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N + 1; i++) {
		Map[0][i] = -1;
		Map[i][0] = -1;
		Map[N + 1][i] = -1;
		Map[i][N + 1] = -1;
	}
	for (int x = 1; x <= N; x++) {
		string Input;
		cin >> Input;
		for (int y = 1; y <= M; y++) {
			Map[x][y] = Input[y - 1] - '0';
			DistanceToStart[x][y] = 2147483647;
			DistanceToEnd[x][y] = 2147483647;
		}
	}

	MyQueue.push(make_tuple(1, 1, 1));
	DistanceToStart[1][1] = 1;
	while (!MyQueue.empty())
	{
		int nowDistance, nowX, nowY;
		tie(nowDistance, nowX, nowY) = MyQueue.top();
		MyQueue.pop();

		if (DistanceToStart[nowX][nowY] < nowDistance)
			continue;

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];

			if (Map[nextX][nextY] == 0) {
				if (DistanceToStart[nextX][nextY] > nowDistance + 1) {
					MyQueue.push(make_tuple(nowDistance + 1, nextX, nextY));
					DistanceToStart[nextX][nextY] = nowDistance + 1;
				}
			}
			else if (Map[nextX][nextY] == 1) {
				if (DistanceToStart[nextX][nextY] > nowDistance + 1) {
					DistanceToStart[nextX][nextY] = nowDistance + 1;
				}
			}
		}
	}

	MyQueue.push(make_tuple(1, N, M));
	DistanceToEnd[N][M] = 1;
	while (!MyQueue.empty())
	{
		int nowDistance, nowX, nowY;
		tie(nowDistance, nowX, nowY) = MyQueue.top();
		MyQueue.pop();

		if (DistanceToEnd[nowX][nowY] < nowDistance)
			continue;

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];

			if (Map[nextX][nextY] == 0) {
				if (DistanceToEnd[nextX][nextY] > nowDistance + 1) {
					MyQueue.push(make_tuple(nowDistance + 1, nextX, nextY));
					DistanceToEnd[nextX][nextY] = nowDistance + 1;
				}
			}
			else if (Map[nextX][nextY] == 1) {
				if (DistanceToEnd[nextX][nextY] > nowDistance + 1) {
					DistanceToEnd[nextX][nextY] = nowDistance + 1;
				}
			}
		}
	}

	int Answer = DistanceToStart[N][M];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (Map[i][j] == 1 && DistanceToStart[i][j] != 2147483647 && DistanceToEnd[i][j] != 2147483647) {
				Answer = min(Answer, DistanceToStart[i][j] + DistanceToEnd[i][j] - 1);
			}
		}
	}
	if (Answer == 2147483647)
		cout << "-1";
	else
		cout << Answer;
}