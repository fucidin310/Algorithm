#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> Tree;

int ToIntFromChar(char c);
char TocharFromInt(int i);
void PreTra(int start);
void InTra(int start);
void PostTra(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	Tree.resize(N);
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		Tree[ToIntFromChar(root)].first = ToIntFromChar(left);
		Tree[ToIntFromChar(root)].second = ToIntFromChar(right);
	}

	PreTra(0);
	cout << '\n';
	InTra(0);
	cout << '\n';
	PostTra(0);
	cout << '\n';
}

int ToIntFromChar(char c) {
	if (c == '.')
		return -1;
	else
		return (int)(c - 'A');
}

char TocharFromInt(int i) {
	return (char)('A' + i);
}

void PreTra(int start) {
	if (start == -1)
		return;

	cout << TocharFromInt(start);
	PreTra(Tree[start].first);
	PreTra(Tree[start].second);
}

void InTra(int start) {
	if (start == -1)
		return;

	InTra(Tree[start].first);
	cout << TocharFromInt(start);
	InTra(Tree[start].second);
}

void PostTra(int start) {
	if (start == -1)
		return;

	PostTra(Tree[start].first);
	PostTra(Tree[start].second);
	cout << TocharFromInt(start);
}