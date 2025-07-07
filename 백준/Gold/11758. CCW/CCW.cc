#include <iostream>
using namespace std;

typedef pair<int, int> node;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	node firstNode;
	node secondNode;
	node thirdNode;

	cin >> firstNode.first >> firstNode.second >> secondNode.first >> secondNode.second >> thirdNode.first >> thirdNode.second;

	int output = (secondNode.first - firstNode.first) * (thirdNode.second - firstNode.second) - (thirdNode.first - firstNode.first) * (secondNode.second - firstNode.second);

	if (output > 0) cout << 1;
	else if (output < 0) cout << -1;
	else cout << 0;
}
