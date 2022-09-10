#include <iostream>
#include <string>
using namespace std;

int n, m;
char MAP[101][101];
int visited[101][101];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int wPower = 0;
int bPower = 0;
void dfs(int y, int x, char color) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
		if (visited[ny][nx] != 0) continue;
		if (MAP[ny][nx] != color) continue;

		if (color == 'W') wPower += 1;
		else if (color == 'B') bPower += 1;

		visited[ny][nx] = 1;
		dfs(ny, nx, color);
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			MAP[i][j] = str[j];
		}
	}

	int Wres = 0;
	int Bres = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != 0) continue;
			if (MAP[i][j] == 'W') {
				visited[i][j] = 1;
				wPower += 1;
				dfs(i, j, 'W');

				Wres += (wPower * wPower);
				wPower = 0;
			}
			else if (MAP[i][j] == 'B') {
				visited[i][j] = 1;
				bPower += 1;
				dfs(i, j, 'B');

				Bres += (bPower * bPower);
				bPower = 0;
			}
		}
	}

	cout << Wres << " " << Bres;

	return 0;
}