#include <iostream>
using namespace std;

int N;
bool isPrime[4000001];
void Func(int n);
int Answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 4000000; i++)
		isPrime[i] = true;

	for (int i = 2; i <= 2000; i++) {
		if (isPrime[i]) {
			int n = 2;
			while (true)
			{
				if (i * n > 4000000)
					break;

				isPrime[i * n] = false;
				n++;
			}
		}
	}

	cin >> N;
	for (int i = 2; i <= N; i++) {
		Func(i);
	}
	cout << Answer;
}

void Func(int n) {
	if (!isPrime[n])
		return;

	int temp = 0;
	for (int i = n; i <= N; i++) {
		if (!isPrime[i])
			continue;

		temp += i;

		if (temp == N) {
			Answer++;
			return;
		}
		
		if (temp > N)
			return;
	}
}