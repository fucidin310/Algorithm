#include <iostream>
using namespace std;

int N;
int RGBCostList[1000][3];	// 0: R, 1: G, 2: B
int B[1000][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	fill(&B[0][0], &B[N - 1][2] + 1, 2147483647 - 1001);
	for (int i = 0; i < N; i++) {
		cin >> RGBCostList[i][0] >> RGBCostList[i][1] >> RGBCostList[i][2];
	}
	B[0][0] = RGBCostList[0][0];
	B[0][1] = RGBCostList[0][1];
	B[0][2] = RGBCostList[0][2];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			B[i][j] = min(B[i][j], min(B[i - 1][(j + 1) % 3] + RGBCostList[i][j], B[i - 1][(j + 2) % 3] + RGBCostList[i][j]));
		}
	}

	int Answer = min(B[N - 1][0], min(B[N - 1][1], B[N - 1][2]));
	cout << Answer;
}