#include <iostream>
using namespace std;

int N;
int Map[15];
int Answer = 0;

void Func(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	Func(1);

	cout << Answer;
}

void Func(int n) {
	if (n == N + 1) {
		Answer++;
		return;
	}

	//새로 놓을 자리
	for (int i = 1; i <= N; i++) {
		//이자리에 놓을 수 있는지
		bool isPossible = true;
		//이미 이전에 놓은 줄
		for (int j = 1; j < n; j++) {
			if (Map[j] == i || Map[j] + (n - j) == i || Map[j] - (n - j) == i) {
				isPossible = false;
				break;
			}
		}
		if (isPossible) {
			Map[n] = i;
			Func(n + 1);
		}
	}
}