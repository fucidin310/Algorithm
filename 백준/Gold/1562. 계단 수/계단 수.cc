#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int mod = 1000000000;
queue<tuple<int, int, int>> MyQueue;
int temp[10][1024];
int N;
int Answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= 9; i++) {
		MyQueue.push(make_tuple(i, 1 << i, 1));
	}

	for (int i = 2; i <= N; i++) {
		while (!MyQueue.empty())
		{
			int lastNum, visitedNum, Num;
			tie(lastNum, visitedNum, Num) = MyQueue.front();
			MyQueue.pop();

			if (lastNum == 0) {
				temp[1][visitedNum | 1 << 1] = (temp[1][visitedNum | 1 << 1] + Num) % mod;
			}
			else if (lastNum == 9) {
				temp[8][visitedNum | 1 << 8] = (temp[8][visitedNum | 1 << 8] + Num) % mod;
			}
			else {
				temp[lastNum - 1][visitedNum | 1 << (lastNum - 1)] = (temp[lastNum - 1][visitedNum | 1 << (lastNum - 1)] + Num) % mod;
				temp[lastNum + 1][visitedNum | 1 << (lastNum + 1)] = (temp[lastNum + 1][visitedNum | 1 << (lastNum + 1)] + Num) % mod;
			}
		}

		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1024; k++) {
				if (temp[j][k] != 0) {
					MyQueue.push(make_tuple(j, k, temp[j][k]));
					temp[j][k] = 0;
				}
			}
		}
	}

	while (!MyQueue.empty())
	{
		if ((get<1>(MyQueue.front()) & 1023) == 1023) {
			Answer = (Answer + get<2>(MyQueue.front())) % mod;
		}
		MyQueue.pop();
	}

	cout << Answer;
}