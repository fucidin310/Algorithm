#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		arr.push_back(input);
	}

	int answer_left = 0;
	int answer_right = N - 1;

	int index_left = 0;
	int index_right = N - 1;

	int min_sum = 2147483647;

	while (index_left < index_right)
	{
		int sum = arr[index_left] + arr[index_right];
		if (min_sum > abs(sum))
		{
			min_sum = abs(sum);
			answer_left = index_left;
			answer_right = index_right;
		}

		if (sum > 0) index_right--;
		else if (sum < 0) index_left++;
		else break;
	}

	cout << arr[answer_left] << ' ' << arr[answer_right];
}
