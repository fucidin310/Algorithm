#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
map<string, int> Input;
vector<string> Output;

bool cmp(string A, string B) {
	return A < B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		Input.insert({ temp, 1 });
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (Input[temp] == 1) {
			Output.push_back(temp);
		}
	}
	sort(Output.begin(), Output.end(), cmp);
	cout << Output.size() << '\n';
	for (int i = 0; i < Output.size(); i++) {
		cout << Output[i] << '\n';
	}
}