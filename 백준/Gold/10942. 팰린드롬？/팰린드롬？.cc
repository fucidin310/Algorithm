#include <iostream>
using namespace std;

int N, M;
int Seq[2000];
bool DP[2000][2000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Seq[i];
	}

	for (int size = 0; size < N; size++) {
		for (int start = 0; start < N; start++) {
			int end = start + size;
			if (end >= N) break;

			if (Seq[start] == Seq[end]) {
				if (start == end || start + 1 == end || DP[start + 1][end - 1]) {
					DP[start][end] = true;
				}
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		if (DP[s - 1][e - 1]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}