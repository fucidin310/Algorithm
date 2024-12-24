#include <iostream>
using namespace std;

int A, B;
int Answer = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	while (true)
	{
		if (A == B) {
			break;
		}

		if (A > B) {
			Answer = -1;
			break;
		}

		if (B % 10 == 1) {
			B = (B - 1) / 10;
		}
		else if(B % 2 == 0){
			B /= 2;
		}
		else {
			Answer = -1;
			break;
		}

		Answer++;
	}

	cout << Answer;
}