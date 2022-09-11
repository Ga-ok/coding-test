#include<iostream>
#include<string>
using namespace std;

int r, c;
char MAP[251][251];
int visited[251][251];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int sheepCnt = 0;
int WolfCnt = 0;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (MAP[ny][nx] == '#') continue;
		if (visited[ny][nx] != 0) continue;

		if (MAP[ny][nx] == 'v') WolfCnt += 1;
		if (MAP[ny][nx] == 'k') sheepCnt += 1;

		visited[ny][nx] = 1;
		dfs(ny, nx);

	}

}

int main() {

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			MAP[i][j] = str[j];
		}
	}

	int resSheep = 0;
	int resWolf = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] == '#') continue;
			if (MAP[i][j] == '.') continue;

			visited[i][j] = 1;
			if (MAP[i][j] == 'v') WolfCnt += 1;
			if (MAP[i][j] == 'k') sheepCnt += 1;
			dfs(i, j);

			if (sheepCnt > WolfCnt) {
				resSheep += sheepCnt;
			}
			else {
				resWolf += WolfCnt;
			}

			sheepCnt = 0;
			WolfCnt = 0;
		}
	}

	cout << resSheep << " " << resWolf;

	return 0;
}