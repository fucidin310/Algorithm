#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MyQueue;

int N;
int Answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		MyQueue.push(make_pair(e, s));
	}
	int curTime = 0;
	while (!MyQueue.empty()) {
		if (MyQueue.top().second >= curTime) {
			curTime = MyQueue.top().first;
			MyQueue.pop();
			Answer++;
		}
		else if(MyQueue.top().second < curTime) {
			MyQueue.pop();
		}
		else {
			curTime++;
		}
	}
	cout << Answer;
}