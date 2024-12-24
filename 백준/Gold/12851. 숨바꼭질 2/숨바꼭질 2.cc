#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Time = -1; 
int Count;
queue<pair<int, int>> MyQueue;
bool visited[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	MyQueue.push(make_pair(N, 0));

	while (!MyQueue.empty())
	{
		int nowPos = MyQueue.front().first;
		int nowTime = MyQueue.front().second;
		MyQueue.pop();
		visited[nowPos] = true;

		if (Time != -1 && Time < nowTime) {
			continue;
		}
		if (nowPos == K) {
			Count++;
			Time = nowTime;
			continue;
		}


		if (nowPos - 1 >= 0 && !visited[nowPos - 1])
			MyQueue.push(make_pair(nowPos - 1, nowTime + 1));

		if (nowPos + 1 <= 100000 && !visited[nowPos + 1])
			MyQueue.push(make_pair(nowPos + 1, nowTime + 1));

		if (nowPos * 2 <= 100000 && !visited[nowPos * 2])
			MyQueue.push(make_pair(nowPos * 2, nowTime + 1));
	}

	cout << Time << "\n" << Count;
}