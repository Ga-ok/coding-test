#include <iostream>

using namespace std;

int n, m;
int MAP[501][501];
int visited[501][501];
int drawSize = 0;
int cnt = 0;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != 1) continue;

		visited[ny][nx] = 1;
		drawSize += 1;
		dfs(ny, nx);
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	int maxSize = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] != 1) continue;

			drawSize += 1;
			visited[i][j] = 1;
			dfs(i, j);
			cnt += 1;

			if (drawSize > maxSize) maxSize = drawSize;
			drawSize = 0;
		}
	}

	if (cnt != 0) {
		cout << cnt << "\n";
		cout << maxSize << "\n";
	}
	else {
		cout << cnt << "\n";
		cout << 0 << "\n";
	}
	
	return 0;
}