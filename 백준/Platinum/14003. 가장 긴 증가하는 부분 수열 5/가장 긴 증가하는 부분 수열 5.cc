#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int Inputs[1000001];
int DP[1000001];

int length;
vector<int> LIS;

int BinarySearch(int start, int end, int value) {
	while (start < end)
	{
		int mid = start + (end - start) / 2;

		if (LIS[mid] < value) start = mid + 1;
		else if (LIS[mid] > value) end = mid;
		else return mid;
	}

	return start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> Inputs[0];
	DP[0] = 1;
	LIS.push_back(Inputs[0]);
	length = 1;

	for (int i = 1; i < N; i++) {
		cin >> Inputs[i];
		if (LIS[length - 1] < Inputs[i]) {
			LIS.push_back(Inputs[i]);
			length++;
			DP[i] = length;
		}
		else {
			int index = BinarySearch(0, length - 1, Inputs[i]);

			if (index == 0 || LIS[index - 1] < Inputs[i]) {
				LIS[index] = Inputs[i];
			}
			DP[i] = index + 1;
		}
	}

	cout << length << "\n";
	stack<int> Answer;
	for (int i = N - 1; i >= 0; i--) {
		if (DP[i] == length) {
			length--;
			Answer.push(Inputs[i]);
		}
	}

	while (!Answer.empty())
	{
		cout << Answer.top() << " ";
		Answer.pop();
	}
}