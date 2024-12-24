#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct Jewel{
	int weight;
	int price;

	bool operator< (const Jewel& temp) const {
		return weight < temp.weight;
	}
}Jewel;

struct compare
{
	bool operator() (Jewel a, Jewel b) {
		return a.price < b.price;
	}
};

int N, K;
int M, V, C;

Jewel JewelList[300000];
int BagList[300000];
priority_queue<Jewel, vector<Jewel>, compare> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		JewelList[i] = Jewel{ M, V };
	}
	sort(JewelList, JewelList + N);
	for (int i = 0; i < K; i++) {
		cin >> C;
		BagList[i] = C;
	}
	sort(BagList, BagList + K);

	long long Answer = 0;
	int index = 0;
	for (int i = 0; i < K; i++) {
		for (int j = index; j < N; j++) {
			if (JewelList[j].weight > BagList[i])
				break;
			else
			{
				pq.push(JewelList[j]);
				index++;
			}
		}
		if (!pq.empty()) {
			Answer += pq.top().price;
			pq.pop();
		}
	}
	cout << Answer;
}