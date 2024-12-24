#include <iostream>
#include <vector>
using namespace std;

string Input1, Input2;
vector<char> Output;

int BP[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> Input1 >> Input2;

	for (int i = 1; i <= Input1.size(); i++) {
		for (int j = 1; j <= Input2.size(); j++) {
			if (Input1[i - 1] == Input2[j - 1])
				BP[i][j] = BP[i - 1][j - 1] + 1;
			else
				BP[i][j] = max(BP[i - 1][j], BP[i][j - 1]);
		}
	}
	cout << BP[Input1.size()][Input2.size()];
}