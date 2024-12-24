#include <iostream>
using namespace std;

int Answer;
string Input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		if (!(cin >> Input).eof()) {
			Answer++;
		}
		else {
			cout << Answer;
			break;
		}
	}
}