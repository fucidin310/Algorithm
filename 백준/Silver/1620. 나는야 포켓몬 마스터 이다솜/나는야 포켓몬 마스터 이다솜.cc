#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map<string, int> Map;
vector<string> Arr;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;
		Map.insert({ temp, i });
		Arr.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			int tempInt = 0;
			for (int n = temp.size() - 1; n >= 0; n--) {
				tempInt += (temp[n] - '0') * pow(10, temp.size() - 1 - n);
			}
			cout << Arr[tempInt - 1] << '\n';
		}
		else {
			cout << Map[temp] << '\n';
		}
	}
}