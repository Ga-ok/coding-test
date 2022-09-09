#include <iostream>

using namespace std;

int n, m;
int MAP[1001][1001];
int visited[1001][1001];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int cnt = 0;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != 255) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);

	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int r, g, b;
			cin >> r >> g >> b;
			int color = (r + g + b) / 3;
			MAP[i][j] = color;
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] >= T) MAP[i][j] = 255;
			else MAP[i][j] = 0;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 255) {
				if (visited[i][j] != 0) continue;
				dfs(i, j);
				cnt += 1;
			}
		}
	}

	cout << cnt;

	return 0;

}