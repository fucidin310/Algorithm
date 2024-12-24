#include <iostream>
#include <map>
using namespace std;

pair<int, int> input[3];
map<int, int> X;
map<int, int> Y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> input[i].first >> input[i].second;
		X[input[i].first]++;
		Y[input[i].second]++;
	}
	int x, y;
	for (int i = 0; i < 3; i++) {
		if (X[input[i].first] == 1)
			x = input[i].first;

		if (Y[input[i].second] == 1)
			y = input[i].second;
	}
	cout << x << ' ' << y;
}