#include <iostream>

using namespace std;

string Input;
bool isVowel(char c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> Input;
		if (Input == "end")
			return 0;

		bool isAcceptable = true;
		bool hasVowel = isVowel(Input[0]);
		char beforeChar = Input[0];
		int stack2 = 0;

		for (int i = 1; i < Input.size(); i++) {
			if (!isAcceptable)
				break;

			if (!hasVowel && isVowel(Input[i])) {
				hasVowel = true;
			}

			if (isVowel(beforeChar) == isVowel(Input[i])) {
				stack2++;
				if (stack2 == 2)
					isAcceptable = false;
			}
			else
				stack2 = 0;

			if (beforeChar == Input[i]) {
				if (Input[i] != 'e' && Input[i] != 'o') {
					isAcceptable = false;
				}
			}
			beforeChar = Input[i];
		}
		
		if (!hasVowel)
			isAcceptable = false;

		if (isAcceptable)
			cout << "<" << Input << "> is acceptable.\n";
		else
			cout << "<" << Input << "> is not acceptable.\n";
	}
}

bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}
