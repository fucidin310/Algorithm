#include <iostream>
using namespace std;

int N, M;
int Answer[9];
void PrintAnswer(int index, int count) {
	if (index > N) {
		return;
	}
	Answer[count] = index;

	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << Answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	PrintAnswer(index, count + 1);
	PrintAnswer(index + 1, count);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	PrintAnswer(1, 0);
}