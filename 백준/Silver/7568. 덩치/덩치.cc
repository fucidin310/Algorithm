#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Human
{
	int height;
	int weight;
};

int N;
vector<Human> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i].height >> A[i].weight;
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (A[i].height < A[j].height && A[i].weight < A[j].weight) {
				rank++;
			}
		}

		cout << rank << ' ';
	}
}
