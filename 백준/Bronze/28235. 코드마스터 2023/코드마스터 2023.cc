#include <iostream>
#include <map>
using namespace std;

map<string, string> MyMap;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	MyMap.insert({ "SONGDO", "HIGHSCHOOL" });
	MyMap.insert({ "CODE", "MASTER" });
	MyMap.insert({ "2023", "0611" });
	MyMap.insert({ "ALGORITHM", "CONTEST" });

	string Input;
	cin >> Input;
	cout << MyMap[Input];
}