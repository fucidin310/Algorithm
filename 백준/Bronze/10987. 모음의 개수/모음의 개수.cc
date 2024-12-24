#include <iostream>
using namespace std;

string Input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Input;
	int Answer = 0;

	for (int i = 0; i < Input.size(); i++) {
		if (Input[i] == 'a' || Input[i] == 'e' || Input[i] == 'i' || Input[i] == 'o' || Input[i] == 'u')
			Answer++;
	}
	cout << Answer;
}
