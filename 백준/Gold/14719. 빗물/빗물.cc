#include <iostream>
#include <vector>
using namespace std;

int H, W;
int Answer;
vector<int> BlockList;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxHPos = 0;
	cin >> H >> W;
	BlockList.resize(W);
	for (int i = 0; i < W; i++) {
		cin >> BlockList[i];
		if (BlockList[maxHPos] < BlockList[i]) {
			maxHPos = i;
		}
	}


	int start = 0;
	for (int i = 0; i <= maxHPos; i++) {
		if (BlockList[i] >= BlockList[start]) {
			start = i;
		}
		else{
			Answer += BlockList[start] - BlockList[i];
		}
	}
	start = W - 1;
	for (int i = W - 1; i >= maxHPos; i--) {
		if (BlockList[i] >= BlockList[start]) {
			start = i;
		}
		else {
			Answer += BlockList[start] - BlockList[i];
		}
	}
	cout << Answer;
}