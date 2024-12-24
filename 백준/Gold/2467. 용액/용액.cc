#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> PlusA;
vector<int> MinusA;

int Answer1 = 2147483647, Answer2 = 0;

int BinarySearch(int value, int s, int e);
void CompareAnswer(int A, int B);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 0) {
			PlusA.push_back(temp);
			int nowIndex = i - MinusA.size();
			if(MinusA.size() > 0)
				CompareAnswer(BinarySearch(-PlusA[nowIndex], 0, MinusA.size() - 1), PlusA[nowIndex]);
			if (PlusA.size() > 1)
				CompareAnswer(PlusA[nowIndex - 1], PlusA[nowIndex]);
		}
		else {
			MinusA.push_back(temp);
			if(MinusA.size() > 1)
				CompareAnswer(MinusA[i - 1], MinusA[i]);
		}
	}
	cout << Answer1 << ' ' << Answer2;
}

int BinarySearch(int value, int s, int e)
{
	int m = (s + e) / 2;

	if (s == m || e == m) {
		if (abs(MinusA[s] - value) > abs(MinusA[e] - value))
			return MinusA[e];
		else
			return MinusA[s];
	}

	if (MinusA[m] == value)
		return value;
	else if (MinusA[m] > value) {
		return BinarySearch(value, s, m);
	}
	else
		return BinarySearch(value, m, e);
}

void CompareAnswer(int A, int B) {
	if (abs(Answer1 + Answer2) > abs(A + B)) {
		if (A > B) {
			int temp = A;
			A = B;
			B = temp;
		}

		Answer1 = A;
		Answer2 = B;
	}
}