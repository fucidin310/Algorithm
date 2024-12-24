#include <iostream>
using namespace std;

int CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
	long long temp = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);

	if (temp < 0) return -1;
	else if (temp > 0) return 1;
	else return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	pair<long long, long long> p1, p2, p3, p4;

	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	cin >> p3.first >> p3.second >> p4.first >> p4.second;

	int CCW1, CCW2, CCW3, CCW4;
	CCW1 = CCW(p1, p2, p3);
	CCW2 = CCW(p1, p2, p4);
	CCW3 = CCW(p3, p4, p1);
	CCW4 = CCW(p3, p4, p2);

	//교차할 때
	if (CCW1 * CCW2 < 0 && CCW3 * CCW4 < 0) {
		cout << 1;
	}
	//두선분이 일직선에 있을 때
	else if (CCW1 == 0 && CCW2 == 0) {
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		if (p1 <= p4 && p2 >= p3) cout << 1;
		else cout << 0;
	}
	//점 하나만 선분에 닿을 때(== 0 은 A선분의 점이 B선분과 일직선, <= 0 은 A선분이 B선분의 연장선을 지나가는, 즉...)
	else if ((CCW1 * CCW2 == 0 && CCW3 * CCW4 <= 0) || (CCW1 * CCW2 <= 0 && CCW3 * CCW4 == 0)) {
		cout << 1;
	}
	//그 외
	else {
		cout << 0;
	}
}
