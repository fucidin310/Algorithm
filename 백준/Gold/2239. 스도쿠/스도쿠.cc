#include <iostream>
using namespace std;

int map[9][9];
//0 : 가로, 1 : 세로, 2 : 대각선
int DP[3][9];

void AddDP(int x, int y, int value) {
	DP[0][y] |= 1 << value;
	DP[1][x] |= 1 << value;
	DP[2][x / 3 + 3 * (y / 3)] |= 1 << value;
}

void RemoveDP(int x, int y, int value) {
	DP[0][y] &= ~(1 << value);
	DP[1][x] &= ~(1 << value);
	DP[2][x / 3 + 3 * (y / 3)] &= ~(1 << value);
}

bool CheckDP(int x, int y, int value) {
	if (DP[0][y] & 1 << value) return false;
	else if (DP[1][x] & 1 << value) return false;
	else if (DP[2][x / 3 + 3 * (y / 3)] & 1 << value) return false;
	else return true;
}

void Backtracking(int x, int y) {
	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[j][i];
			}
			cout << "\n";
		}
		exit(0);
	}

	if (x == 9) {
		return Backtracking(0, y + 1);
	}

	if (map[x][y] != 0) {
		return Backtracking(x + 1, y);
	}

	for (int i = 1; i <= 9; i++) {
		if (!CheckDP(x, y, i)) {
			continue;
		}

		map[x][y] = i;
		AddDP(x, y, i);

		Backtracking(x + 1, y);

		map[x][y] = 0;
		RemoveDP(x, y, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 0; y < 9; y++) {
		string temp;
		cin >> temp;
		for (int x = 0; x < 9; x++) {
			map[x][y] = temp[x] - '0';
			if (map[x][y] != 0) {
				AddDP(x, y, map[x][y]);
			}
		}
	}

	Backtracking(0, 0);
}