#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int Answer;

int main() {
	cin >> N >> r >> c;
	for (int i = N; i >= 1; i--) {
		int tempR, tempC;
		int Length = pow(2, i - 1);
		int Area = Length * Length;
		tempR = r / Length;
		tempC = c / Length;
		Answer += (tempR * Area * 2 + tempC * Area);
		r -= tempR * Length;
		c -= tempC * Length;
	}

	cout << Answer;
}