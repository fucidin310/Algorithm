#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> valueArr;
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		valueArr.push_back(value);
	}
	sort(valueArr.begin(), valueArr.end());

	int start = 0;
	int end = 0;

	int output = 2147483647;

	while (start < N && end < N)
	{
		if (valueArr[end] - valueArr[start] >= M)
		{
			output = min(output, valueArr[end] - valueArr[start]);
			start++;
		}
		else
		{
			end++;
		}
	}
	
	cout << output;
}
