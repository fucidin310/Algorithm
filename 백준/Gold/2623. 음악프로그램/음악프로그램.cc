#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> Arr[1001];
int degree[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;

		int now, pre;
		pre = 0;

		for (int j = 0; j < n; j++) {
			cin >> now;

			if (pre != 0) {
				Arr[pre].push_back(now);
				degree[now]++;
			}

			pre = now;
		}
	}

	vector<int> Answer;
	queue<int> myQueue;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			myQueue.push(i);
		}
	}

	while (!myQueue.empty())
	{
		int now = myQueue.front();
		myQueue.pop();

		Answer.push_back(now);
		for (int i : Arr[now]) {
			degree[i]--;
			if (degree[i] == 0) {
				myQueue.push(i);
			}
		}
	}

	if (Answer.size() != N) {
		cout << '0';
	}
	else {
		for (int i = 0; i < Answer.size(); i++) {
			cout << Answer[i] << "\n";
		}
	}
}