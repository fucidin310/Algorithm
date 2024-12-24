#include <iostream>
#include <vector>
using namespace std;

int N, M;
int Answer;
vector<int> PeopleList;
vector<int> FirstPeopleList;

void Union(int num1, int num2);
int Find(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	PeopleList.resize(N + 1);
	for (int i = 1; i < PeopleList.size(); i++) {
		PeopleList[i] = i;
	}

	int KnownNum;
	cin >> KnownNum;
	for (int i = 0; i < KnownNum; i++) {
		int temp;
		cin >> temp;

		PeopleList[temp] = 0;
	}

	for (int i = 0; i < M; i++) {
		int PNum, FirstP;
		cin >> PNum >> FirstP;
		FirstPeopleList.push_back(FirstP);
		for (int j = 1; j < PNum; j++) {
			int temp;
			cin >> temp;
			Union(FirstP, temp);
		}
	}

	for (int i = 0; i < FirstPeopleList.size(); i++) {
		if (Find(FirstPeopleList[i]) != Find(0))
			Answer++;
	}
	cout << Answer;
}

void Union(int num1, int num2) {
	PeopleList[Find(num2)] = PeopleList[Find(num1)];
}

int Find(int num) {
	if (num == PeopleList[num])
		return num;
	else {
		return Find(PeopleList[num]);
	}
}