#include <iostream>

using namespace std;
int map[1000][1000];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main() {

	int n;
	cin >> n;

	int number;
	cin >> number;

	int sy = (n / 2)-1;
	int sx = (n / 2)-1;

	int ny, nx;
	int cnt = 1;
	map[sy+1][sx+1] = cnt;
	int flag = 0;
	int dist = 2;
	while (1) {
		
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < dist; k++) {

				ny = sy + dy[i];
				nx = sx + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
					flag = 1;
					break;
				}
				if (map[ny][nx] == 0) {
					cnt++;
					map[ny][nx] = cnt;
				}
				sy = ny;
				sx = nx;
			}
		}

		sy -= 1;
		sx -= 1;

		dist+=2;

		if (flag == 1) break;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == number) {
				cout << i + 1 << " " << j + 1;
				break;
			}
		}
	}

	return 0;
}