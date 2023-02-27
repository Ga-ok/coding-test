#include <iostream>
#include <string>
using namespace std;

int MAP[201][201];
int MAP_copy[201][201];
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int main() {

	int R, C, N;
	cin >> R >> C >> N;

	int time = 1;

	// 처음에 봄버맨이 폭탄 설치 + 아무것도 하지 않음
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char ch;
			cin >> ch;
			if (ch == '.') MAP[i][j] = 0;
			else MAP[i][j] = 2;
		}
	}

	while (true) {
		if (time == N) break;
		time += 1;
		// 폭탄이 설치되어 있지 않은 모든 칸에 폭탄 설치
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (MAP[i][j] == 0) MAP[i][j] = 3;
				else MAP[i][j] -= 1;
			}
		}

		if (time == N) break;

		time += 1;
		// 폭탄 폭발
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				MAP_copy[i][j] = MAP[i][j];
			}
		}
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (MAP[i][j] == 1) {
					MAP_copy[i][j] = 0;
					for (int d = 0; d < 4; d++) {
						int nr = i + dr[d];
						int nc = j + dc[d];
						if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
						MAP_copy[nr][nc] = 0;
					}
				}
				else {
					if(MAP_copy[i][j]!=0) MAP_copy[i][j] -= 1;
				}
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				MAP[i][j] = MAP_copy[i][j];
			}
		}

		if (time == N) break;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << "\n";
	}
	
}