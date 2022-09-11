#include <iostream>
#include <string>
#include <queue>
using namespace std;

char MAP[26][26];
int visited[26][26];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int n;
int house = 0;
void dfs(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != '1') continue;

		visited[ny][nx] = 1;
		house += 1;
		dfs(ny, nx);
	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			MAP[i][j] = str[j];
		}
	}

	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> houses;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] != '1') continue;

			visited[i][j] = 1;
			house += 1;
			dfs(i, j);
			cnt += 1;

			houses.push(house);
			house = 0;
		}
	}

	cout << cnt << "\n";
	while (!houses.empty()) {
		int now = houses.top();
		houses.pop();
		cout << now << "\n";
	}

	return 0;
}