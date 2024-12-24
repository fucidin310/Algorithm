#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> edge;

vector<edge> edges;
vector<int> Distance;

int T, N, M, W;
int s, e, t;
bool isPossible;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T > 0)
	{
		T--;

		edges.clear();
		Distance.clear();

		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			edges.push_back(make_tuple(s, e, t));
			edges.push_back(make_tuple(e, s, t));
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			edges.push_back(make_tuple(s, e, -t));
		}
		
		Distance.resize(N + 1, 2147483647 - 10001);
		Distance[1] = 0;

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < edges.size(); j++) {
				int start, end, value;
				tie(start, end, value) = edges[j];
				if (Distance[end] > Distance[start] + value) {
					Distance[end] = Distance[start] + value;
				}
			}
		}

		isPossible = false;
		for (int i = 0; i < edges.size(); i++) {
			int start, end, value;
			tie(start, end, value) = edges[i];
			if (Distance[end] > Distance[start] + value) {
				isPossible = true;
				break;
			}
		}

		if (isPossible) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}