#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
};

int n, m;
int MAP[21][21];
int visited[21][21];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int maxCnt = -1;

void bfs(int y, int x) {

	queue<Node> q;
	q.push({ y, x });
	visited[y][x] = 1;

	int cnt = 0;

	if (MAP[y][x] == 1) cnt++;

	int k;
	while (!q.empty()) {

		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny, nx });

			if (MAP[ny][nx] == 1) cnt++;
			k = visited[ny][nx];
		}

		int cost = (cnt * m) - ((k*k) + ((k-1)*(k-1)));

		if (cost < 0) continue;
		if (maxCnt < cnt) maxCnt = cnt;

	}

}

void init_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {

	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> MAP[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				bfs(i, j);
				if (MAP[i][j] == 1) {
					if ((m - 1) >= 0) {
						if (maxCnt < 1) maxCnt = 1;
					}
				}

				// visited 초기화
				init_visited();
			}
		}

		cout << "#" << testcase << " " << maxCnt << "\n";

		maxCnt = -1;
	}

	return 0;
}