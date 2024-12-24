#include <iostream>
#include <vector>

using namespace std;

int P;
vector<int> A;
vector<int> Answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> P;
	Answer.resize(P);
	A.resize(20);

	for (int n = 0; n < P; n++) {
		int testCaseNum;
		cin >> testCaseNum;
		testCaseNum--;
		for (int i = 0; i < 20; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (A[i] < A[j]) {
					int temp = A[i];
					A.erase(A.begin() + i);
					A.insert(A.begin() + j, temp);
					Answer[n] = Answer[n] + i - j;
					continue;
				}
			}
		}
	}

	for (int n = 0; n < P; n++) {
		cout << n + 1 << ' ' << Answer[n] << '\n';
	}
}
