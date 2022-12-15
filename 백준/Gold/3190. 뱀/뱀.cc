#include <iostream>
#include <queue>
using namespace std;

// queue로 관리 가능 

struct Node {
	int y;
	int x;
};

int n;
int MAP[101][101];
int apple[101][101];
char dir[10001];

int time = 0;
int dy[4] = { -1, 0, 1, 0 }; // 상우하좌
int dx[4] = { 0, 1, 0, -1 };
void Dummy() {

	int y = 0;
	int x = 0;
	MAP[y][x] = 1;

	int d = 1;

	queue<Node> q;
	q.push({ y, x });

	while (true) {

		int ny = y + dy[d];
		int nx = x + dx[d];

		// 벽이거나 자기 자신의 몸이 있는지 체크
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
		if (MAP[ny][nx] != 0) break;

		// 사과가 있는지 체크
		if (apple[ny][nx] == 1) {
			apple[ny][nx] = 0;
			MAP[ny][nx] = 1;
			q.push({ ny, nx });
		}
		else if (apple[ny][nx] == 0) {
			MAP[ny][nx] = 1;

			Node tail = q.front();
			q.pop();
			MAP[tail.y][tail.x] = 0;
			q.push({ ny, nx });
		}

		y = ny;
		x = nx;

		time++;

		if (dir[time] == 'D') {
			d = (d + 1) % 4;
		}
		if (dir[time] == 'L') {
			d = (d + 3) % 4;
		}
	}

}

int main() {

	cin >> n;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		apple[y-1][x-1] = 1;
	}

	int l;
	cin >> l;

	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		dir[x] = c;
	}

	Dummy();
	cout << time + 1;
	
	return 0;
}