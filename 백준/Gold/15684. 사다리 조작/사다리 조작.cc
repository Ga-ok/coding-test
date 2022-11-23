#include <iostream>
using namespace std;

int n, m, h;
int MAP[31][11];
int minCnt = 2134567890;

bool isCorrect() {

	for (int i = 1; i <= n; i++) {
		int way = i;
		for (int j = 1; j <= h; j++) {
			if (MAP[j][way] == 1) {
				way++;
			}
			else if (MAP[j][way - 1] == 1) {
				way--;
			}
		}
		if (way != i) return false;
	}
	return true;
}

void dfs(int cnt, int y, int x) {

	if (minCnt <= cnt) return;
	
	// i번 세로선의 결과가 i번이 나오는지 체크
	if (isCorrect()) {
		minCnt = cnt;
		return;
	}

	if (cnt == 3) return;

	for (int i = y; i <= h; i++) {
		for (int j = x; j < n; j++) {
			if (MAP[i][j] == 1) continue;
			if (MAP[i][j - 1] == 1 || MAP[i][j + 1] == 1) continue;
			MAP[i][j] = 1;
			dfs(cnt + 1, i, j);
			MAP[i][j] = 0;
		}
		x = 1;
	}

}

int main() {

	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		MAP[a][b] = 1;
	}

	dfs(0, 1, 1);
	if (minCnt == 2134567890) minCnt = -1;
	cout << minCnt << "\n";

	return 0;
}