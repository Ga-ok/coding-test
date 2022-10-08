#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int y;
	int x;
};

int n;
int MAP[13][13] = { 0 };
vector<Node> cores;

int dy[] = { -1, 1, 0, 0 };  // 상 하 좌 우 
int dx[] = { 0, 0, -1, 1 };

int maxCnt = -1;
int res = 2134567890;

bool isPossible(int y, int x, int direction) {

	int temp = 1;
	int flag = 0;
	while (1) {
		int ny = y + dy[direction] * temp;
		int nx = x + dx[direction] * temp;
		temp++;
		if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
			break;
		}
		if (MAP[ny][nx] != 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) return true;
	if (flag == 1) return false;
}


int drawLine(int y, int x, int direction) {

	int temp = 1;
	int flag = 0;
	while (1) {
		int ny = y + dy[direction] * temp;
		int nx = x + dx[direction] * temp;
		if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
			break;
		}
		MAP[ny][nx] = 2;
		temp++;
	}
	return temp-1;
}

void removeLine(int y, int x, int direction) {

	int temp = 1;
	int flag = 0;
	while (1) {
		int ny = y + dy[direction] * temp;
		int nx = x + dx[direction] * temp;
		temp++;
		if (ny < 0 || ny > n - 1 || nx < 0 || nx > n - 1) {
			break;
		}
		MAP[ny][nx] = 0;
	}
	
}

void dfs(int idx, int powerCnt, int sum) {

	if (idx == cores.size()) {

		if (maxCnt < powerCnt) {
			maxCnt = powerCnt;
			res = sum;
		}
		else if (maxCnt == powerCnt) {
			if (res > sum) {
				res = sum;
			}
		}
		//cout << powerCnt << " " << sum << "\n";

		return;
	}

	for (int i = 0; i < 4; i++) {
		
		if (isPossible(cores[idx].y, cores[idx].x, i)) {
			// 진짜 전선 설치, 전원 연결 코어 수 증가, 전선길이의 합 계산
			int line = drawLine(cores[idx].y, cores[idx].x, i);

			/*cout << "====================\n";
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					cout << MAP[j][k] << " ";
				}
				cout << "\n";
			}
			cout << "=====================\n";*/

			// dfs 돌리기
			dfs(idx + 1, powerCnt + 1, sum + line);

			// 백트래킹, 전선 제거
			removeLine(cores[idx].y, cores[idx].x, i);
		}
	}

	// 전원에 연결 안하는 경우 
	dfs(idx + 1, powerCnt, sum);
}

int main() {

	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> MAP[i][j];
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
				if (MAP[i][j] == 1) cores.push_back({ i, j });
			}
		}

		dfs(0, 0, 0);
		cout << "#"<<testcase <<" " <<res<< "\n";

		//초기화
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 13; j++) {
				MAP[i][j] = 0;
			}
		}
		cores.clear();

		maxCnt = -1;
		res = 2134567890;
		
	}

	return 0;
}