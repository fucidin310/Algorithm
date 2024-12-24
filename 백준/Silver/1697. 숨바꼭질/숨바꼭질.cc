#include <iostream>
#include <queue>
using namespace std;

int N, K;
int B[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MyQueue;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(B, B + 100001, 100001);
	cin >> N >> K;
	B[N] = 0;

	MyQueue.push(make_pair(0, N));
	while (!MyQueue.empty())
	{
		int time = MyQueue.top().first;
		int pos = MyQueue.top().second;
		MyQueue.pop();

		if (pos > 0 && B[pos - 1] > B[pos] + 1) {
			B[pos - 1] = B[pos] + 1;
			MyQueue.push(make_pair(B[pos - 1], pos - 1));
		}
		if (pos < 100001 - 1 && B[pos + 1] > B[pos] + 1) {
			B[pos + 1] = B[pos] + 1;
			MyQueue.push(make_pair(B[pos + 1], pos + 1));
		}
		if ((2 * pos) <= 100001 - 1 && B[2 * pos] > B[pos] + 1) {
			B[2 * pos] = B[pos] + 1;
			MyQueue.push(make_pair(B[2 * pos], 2 * pos));
		}
	}
	cout << B[K];
}