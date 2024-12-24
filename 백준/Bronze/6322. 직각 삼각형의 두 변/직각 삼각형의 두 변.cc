#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	int n = 1;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;

		int Answer = 0;
		string num;
		if (a != -1) 
			Answer += (int)pow(a, 2);
		else 
			num = "a";

		if (b != -1)
			Answer += (int)pow(b, 2);
		else
			num = "b";

		if (c != -1) {
			Answer *= -1;
			Answer += (int)pow(c, 2);
		}
		else
			num = "c";

		if (Answer <= 0) {
			cout << "Triangle #" << n << "\n";
			cout << "Impossible." << "\n\n";
			n++;
			continue;
		}

		cout << "Triangle #" << n << "\n";
		cout << fixed;
		cout.precision(3);
		cout << num + " = " << (float)sqrt(Answer) << "\n\n";
		n++;
	}
}