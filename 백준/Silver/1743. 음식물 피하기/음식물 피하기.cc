#include<iostream>

using namespace std;
int MAP[101][101];
int visited[101][101];
int cnt = 0;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int n, m, k;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != 1) continue;

		visited[ny][nx] = 1;
		cnt += 1;
		dfs(ny, nx);
	}

}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		MAP[y-1][x-1] = 1;
	}

	int maxCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] != 1) continue;
			if (visited[i][j] != 0) continue;

			dfs(i, j);

			if (maxCnt < cnt) maxCnt = cnt;
			cnt = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					visited[i][j] = 0;
				}
			}
		}
	}

	cout << maxCnt;

	return 0;
}