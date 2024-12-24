#include <iostream>
#include <vector>
using namespace std;

string Input;
vector<string> String;

bool Func1(int startIndex, int endIndex);
bool Func2();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Input;
	for (int i = 0; i < Input.size(); i++) {
		String.push_back(string(1, Input[i]));
	}

	while (Func2())
	{

	}

	while (Func1(0, String.size() - 1))
	{

	}

	for (int i = 0; i < String.size(); i++) {
		cout << String[i];
	}
}

bool Func1(int startIndex, int endIndex) {
	//곱셈, 나눗셈
	for (int i = startIndex; i <= endIndex; i++) {
		if (String[i] == "*" || String[i] == "/") {
			String[i - 1] = String[i - 1] + String[i + 1] + String[i];
			String.erase(String.begin() + i);
			String.erase(String.begin() + i);
			endIndex -= 2;
			return true;
		}
	}

	//덧셈, 뺄셈
	for (int i = startIndex; i <= endIndex; i++) {
		if (String[i] == "+" || String[i] == "-") {
			String[i - 1] = String[i - 1] + String[i + 1] + String[i];
			String.erase(String.begin() + i);
			String.erase(String.begin() + i);
			endIndex -= 2;
			return true;
		}
	}

	return false;
}

bool Func2()
{
	bool hasBracket = false;
	int openBracket = 0;
	int	closeBracket = 0;

	for (int i = 0; i < String.size(); i++) {
		if (String[i] == "(") {
			hasBracket = true;
			openBracket = i;
		}

		if (String[i] == ")") {
			closeBracket = i;
			break;
		}
	}

	if (hasBracket) {
		if (Func1(openBracket + 1, closeBracket - 1)) {

		}
		else {
			String.erase(String.begin() + openBracket);
			String.erase(String.begin() + closeBracket - 1);
		}
	}

	return hasBracket;
}
