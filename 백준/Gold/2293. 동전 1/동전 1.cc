#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> Arr;
	vector<int> DP;

	DP.resize(M + 1);

	DP[0] = 1;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		Arr.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = Arr[i]; j <= M; j++)
		{
			DP[j] += DP[j - Arr[i]];
		}
	}

	cout << DP[M];
}
