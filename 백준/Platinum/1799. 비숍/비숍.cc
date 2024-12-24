#include <iostream>
using namespace std;

int N;
int Map[10][10];
int visited[20];
int Answer[2] = {0, 0};

/*
n : 우측위로 가는 대각선
01234
12345
23456
34567
45678

m : x
*/
void Func(int n, int m, int count, int color) {
	Answer[color] = max(Answer[color], count);

	if (m >= N || n - m < 0) {
		Func(n + 2, 0, count, color);
		return;
	}

	if (n >= 2 * N)
		return;


	if (Map[n - m][m] == 1 && visited[2 * m - n + N] == false) {
		visited[2 * m - n + N] = true;
		Func(n + 2, 0, count + 1, color);
		visited[2 * m - n + N] = false;
	}
	Func(n, m + 1, count, color);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> Map[y][x];
		}
	}

	Func(0, 0, 0, 0);
	Func(1, 0, 0, 1);

	cout << Answer[0] + Answer[1];
}