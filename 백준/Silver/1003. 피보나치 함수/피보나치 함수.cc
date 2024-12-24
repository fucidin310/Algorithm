#include <iostream>
using namespace std;

typedef pair<int, int> Answer;
Answer N[41];
int T;

int main() {
	N[0] = Answer(1, 0);
	N[1] = Answer(0, 1);
	for (int i = 2; i <= 40; i++) {
		N[i].first = N[i - 1].first + N[i - 2].first;
		N[i].second = N[i - 1].second + N[i - 2].second;
	}

	cin >> T;
	while (T > 0)
	{
		T--;

		int temp;
		cin >> temp;
		cout << N[temp].first << ' ' << N[temp].second << '\n';
	}
}