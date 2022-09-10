#include <iostream>

using namespace std;

int n;
int MAP[101][101];
int visited[101][101];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void dfs(int y, int x, int height) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] <= height) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx, height);

	}

}

int main() {

	cin >> n;

	int maxHeight = 0;
	int minHeight = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];

			if (maxHeight < MAP[i][j]) maxHeight = MAP[i][j];
			if (minHeight > MAP[i][j]) minHeight = MAP[i][j];
		}
	}

	int maxCnt = 0;
	for (int height = 0; height <= maxHeight; height++) {
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (MAP[i][j] <= height) continue;
				if (visited[i][j] != 0) continue;

				visited[i][j] = 1;
				dfs(i, j, height);
				cnt += 1;
				
			}
		}

		if (maxCnt < cnt) maxCnt = cnt;

		// 초기화
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}
	}

	cout << maxCnt;

	return 0;
}