#include <iostream>
using namespace std;

int N, M;
void PrintNumber(int number);
void DFS(int number, int lastNumber, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(0, 0, 0);
}

void PrintNumber(int number)
{
	int numberCount = 0;
	for (int i = 0; i < N; i++) {
		if (number & 1 << i) {
			numberCount++;
			cout << i + 1;

			if (numberCount == M)
				cout << "\n";
			else
				cout << " ";
		}
	}
}

void DFS(int number, int lastNumber, int depth)
{
	if (depth == M) {
		PrintNumber(number);
		return;
	}

	for (int i = lastNumber; i < N; i++) {
		DFS(1 << i | number, i + 1, depth + 1);
	}
}
