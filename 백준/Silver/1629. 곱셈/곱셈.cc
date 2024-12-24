#include <iostream>
using namespace std;

int A, B, C;
int Modular(int A, int B, int C);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << Modular(A, B, C);
}

int Modular(int A, int B, int C) {
	if (B == 1)
		return A % C;

	long long int k = Modular(A, B / 2, C);
	if (B % 2 == 1)
		return k * k % C * A % C;
	else
		return k * k % C;
}