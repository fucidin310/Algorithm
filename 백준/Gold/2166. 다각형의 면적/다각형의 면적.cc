#include <iostream>
#include <iomanip>
using namespace std;

int N;
double Answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	pair<long long, long long> origin;
	pair<long long, long long> pos1;
	pair<long long, long long> pos2;

	cin >> origin.first >> origin.second;
	cin >> pos1.first >> pos1.second;
	for (int i = 2; i < N; i++) {
		cin >> pos2.first >> pos2.second;
		Answer += (pos1.first - origin.first) * (pos2.second - origin.second) - (pos1.second - origin.second) * (pos2.first - origin.first);
		pos1 = pos2;
	}

	Answer = abs(((Answer / 2.0f) * 10) / 10);
	cout << fixed << setprecision(1) << Answer;
}