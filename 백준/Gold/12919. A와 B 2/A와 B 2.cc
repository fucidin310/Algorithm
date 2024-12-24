#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<string> MyQueue;
string S, T;
void BFS(string s);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> T;

	BFS(T);
}

void BFS(string s)
{
	MyQueue.push(s);

	while (!MyQueue.empty()) {
		if (MyQueue.front() == S) {
			cout << '1';
			return;
		}

		string NowS = MyQueue.front();
		MyQueue.pop();

		if (NowS[NowS.size() - 1] == 'A') {
			string temp = NowS;
			temp.erase(temp.size() - 1);
			MyQueue.push(temp);
		}

		if (NowS[0] == 'B') {
			string temp = NowS;
			reverse(temp.begin(), temp.end());
			temp.erase(temp.size() - 1);
			MyQueue.push(temp);
		}
	}
	cout << '0';
}
