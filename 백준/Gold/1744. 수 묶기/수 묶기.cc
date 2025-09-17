#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> minus;
	vector<int> plus;
	int oneCount = 0;
	int zeroCount = 0;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;

		if (input == 0) zeroCount++;
		else if (input == 1) oneCount++;
		else if (input < 0) minus.push_back(input * -1);
		else plus.push_back(input);
	}

	sort(minus.rbegin(), minus.rend());
	sort(plus.rbegin(), plus.rend());

	int output = oneCount;

	if (minus.size() % 2 == 1 && zeroCount == 0) output -= minus[minus.size() - 1];

	if (plus.size() % 2 == 1) output += plus[plus.size() - 1];

	for (int i = 1; i < plus.size(); i = i + 2)
	{
		output += plus[i - 1] * plus[i];
	}

	for (int i = 1; i < minus.size(); i = i + 2)
	{
		output += minus[i - 1] * minus[i];
	}

	cout << output;
}
