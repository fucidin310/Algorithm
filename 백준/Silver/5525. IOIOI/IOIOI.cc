#include <iostream>
#include <vector>
using namespace std;

int N, M;
string S;
vector<int> A;

int Answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> S;
	A.resize(M);

	int temp = 0;
	for (int i = 0; i < M; i++) {
		if (temp == 0 && S[i] == 'I')
			temp = 1;
		else if (temp == 1 && S[i] == 'O')
			temp = 2;
		else if (temp == 2 && S[i] == 'I') {
			temp = 1;
			A[i] = A[i - 2] + 1;
		}
		else {
			if (S[i] == 'I')
				temp = 1;
			else
				temp = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		if (A[i] >= N)
			Answer++;
	}
	cout << Answer;
}