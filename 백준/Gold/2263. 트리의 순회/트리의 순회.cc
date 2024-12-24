#include <iostream>
using namespace std;

int N;
int Inorder[100000];
int Postorder[100000];

void Func(int InorderStart, int InorderEnd, int PostorderStart, int PostorderEnd) {
	if (InorderStart > InorderEnd) return;

	cout << Postorder[PostorderEnd] << " ";

	if (InorderStart == InorderEnd) return;

	for (int i = InorderStart; i <= InorderEnd; i++) {
		if (Inorder[i] == Postorder[PostorderEnd]) {
			Func(InorderStart, i - 1, PostorderStart, PostorderStart + (i - 1 - InorderStart));
			Func(i + 1, InorderEnd, PostorderStart + (i - 1 - InorderStart) + 1, PostorderEnd - 1);
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Inorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> Postorder[i];
	}

	Func(0, N - 1, 0, N - 1);
}