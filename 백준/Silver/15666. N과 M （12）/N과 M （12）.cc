#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Input[8];

int Answer[8];

void PrintAnswer(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << Answer[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = 0;
	for (int i = 0; i < N; i++) {
		if (temp >= Input[i] || Answer[count - 1] > Input[i])
			continue;

		Answer[count] = Input[i];
		temp = Input[i];
		PrintAnswer(count + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Input[i];
	}
	sort(Input, Input + N);
	PrintAnswer(0);
}