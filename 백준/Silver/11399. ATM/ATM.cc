#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	vector<int> tmpVec;
	int N;

	cin >> N;

	tmpVec.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tmpVec[i];
	}
	sort(tmpVec.begin(), tmpVec.end());

	int Answer = 0;
	for (int i = 0; i < N; i++)
	{
		Answer += tmpVec[i] * (N - i);
	}

	cout << Answer;
}
