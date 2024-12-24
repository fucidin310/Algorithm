#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> Towers;

int FindReceiveTower(int pos, int height);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int Tower;
		cin >> Tower;
		cout << FindReceiveTower(i, Tower) << ' ';
	}
}

int FindReceiveTower(int pos, int height) {
	int returnValue = 0;
	for (int i = Towers.size() - 1; i >= 0; i--) {
		if (Towers[i].second < height)
			Towers.erase(Towers.begin() + i);	
		else if (returnValue == 0) {
			returnValue = Towers[i].first + 1;
			break;
		}
	}
	Towers.push_back(make_pair(pos, height));
	return returnValue;
}