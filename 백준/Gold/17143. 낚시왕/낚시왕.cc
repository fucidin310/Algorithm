#include <iostream>
using namespace std;

int R, C, M;
int Answer = 0;

struct FishInfo
{
	int x = 0, y = 0, dir = 0, speed = 0, size = 0;
};

FishInfo map[100][100];
FishInfo tempMap[100][100];

FishInfo Move(FishInfo fishInfo, int distance) {
	FishInfo output = fishInfo;
	int nextPos = 0;
	switch (fishInfo.dir)
	{
	case 0:
		nextPos = fishInfo.y - distance;
		output.y = nextPos;
		break;
	case 1:
		nextPos = fishInfo.y + distance;
		output.y = nextPos;
		break;
	case 2:
		nextPos = fishInfo.x + distance;
		output.x = nextPos;
		break;
	case 3:
		nextPos = fishInfo.x - distance;
		output.x = nextPos;
		break;
	}

	switch (fishInfo.dir)
	{
	case 0:
		if (nextPos < 0) {
			output.y = 0;
			output.dir = 1;
			return Move(output, -nextPos);
		}
		break;
	case 1:
		if (nextPos >= R) {
			output.y = R - 1;
			output.dir = 0;
			return Move(output, nextPos - R + 1);
		}
		break;
	case 2:
		if (nextPos >= C) {
			output.x = C - 1;
			output.dir = 3;
			return Move(output, nextPos - C + 1);
		}
		break;
	case 3:
		if (nextPos < 0) {
			output.x = 0;
			output.dir = 2;
			return Move(output, -nextPos);
		}
		break;
	}

	return output;
}

void Fishing(int x) {
	for (int i = 0; i < R; i++) {
		if (map[x][i].size != 0) {
			Answer += map[x][i].size;
			map[x][i].size = 0;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		FishInfo temp;
		cin >> temp.y >> temp.x >> temp.speed >> temp.dir >> temp.size;
		temp.x--;
		temp.y--;
		temp.dir--;

		map[temp.x][temp.y] = temp;
	}

	for (int fisherPos = 0; fisherPos < C; fisherPos++) {
		Fishing(fisherPos);

		for (int x = 0; x < C; x++) {
			for (int y = 0; y < R; y++) {
				if (map[x][y].size == 0) continue;

				FishInfo temp = Move(map[x][y], map[x][y].speed);
				if(tempMap[temp.x][temp.y].size <= temp.size){
					tempMap[temp.x][temp.y] = temp;
				}
			}
		}

		for (int x = 0; x < C; x++) {
			for (int y = 0; y < R; y++) {
				map[x][y] = tempMap[x][y];
				tempMap[x][y].size = 0;
			}
		}
	}

	cout << Answer;
}