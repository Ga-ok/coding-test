#include <iostream>

using namespace std;

int m, n;
int MAP[251][251];
int visited[251][251];

int dy[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int y, int x) {

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != 1) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}

}

int main() {

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] != 1) continue;

			visited[i][j] = 1;
			dfs(i, j);

			cnt += 1;
		}
	}

	cout << cnt;

	return 0;
}