#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Tree[1000001];
int Answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Tree[i];
	}
	sort(Tree, Tree + N, greater<int>());

	long long TreeLength = 0;
	for (int i = 0; i < N; i++) {
		TreeLength += (long long)(Tree[i] - Tree[i + 1]) * (i + 1);
		if (TreeLength >= M) {
			Answer = Tree[i + 1];
			Answer += (TreeLength - M) / (i + 1);
			cout << Answer;
			break;
		}
	}
}