#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, k;
int MAP[101][101];
int visited[101][101];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int areaSize = 0;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != 0) continue;

		visited[ny][nx] = 1;
		areaSize += 1;
		dfs(ny, nx);
	}

}


int main() {

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		// 사각형 구역 1로 만들기
		for (int j = m - sy - 1; j >= m - ey; j--) {
			for (int l = sx; l <= ex - 1; l++) {
				MAP[j][l] = 1;
			}
		}
	}

	int cnt = 0;
	//vector<int> areaSizes;
	priority_queue<int, vector<int>, greater<int>> areaSizes;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] != 0) continue;

			visited[i][j] = 1;
			areaSize += 1;
			dfs(i, j);
			cnt += 1;
			areaSizes.push(areaSize);
			areaSize = 0;
		}
	}



	cout << cnt << "\n";
	while (!areaSizes.empty()) {
		int now = areaSizes.top();
		areaSizes.pop();
		cout << now << " ";
	}

	return 0;
}