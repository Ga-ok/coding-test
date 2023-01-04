#include <iostream>
#include <string>
using namespace std;


int n;
char MAP[51][51];

int maxCnt = 0;
void max_len() {
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        char temp = MAP[i][0];
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (temp == MAP[i][j]) {
                cnt++;
            }
            else {
                if (maxCnt < cnt) maxCnt = cnt;
                cnt = 1;
                temp = MAP[i][j];
            }
        }
        if (maxCnt < cnt) maxCnt = cnt;
    }

    cnt = 1;
    for (int i = 0; i < n; i++) {
        char temp = MAP[0][i];
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (temp == MAP[j][i]) {
                cnt++;
            }
            else {
                if (maxCnt < cnt) maxCnt = cnt;
                cnt = 1;
                temp = MAP[j][i];
            }
        }
        if (maxCnt < cnt) maxCnt = cnt;
    }

}

// 열 먼저 탐색
void search_col() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            char tmp;
            if (MAP[i][j] != MAP[i][j + 1]) {
                tmp = MAP[i][j];
                MAP[i][j] = MAP[i][j + 1];
                MAP[i][j + 1] = tmp;

                // 가장 긴 연속 부분 찾기
                max_len();

                char tmp2;
                tmp2 = MAP[i][j];
                MAP[i][j] = MAP[i][j+1];
                MAP[i][j+1] = tmp2;
            }
        }
    }
}

// 행 먼저 탐색
void search_row() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            char tmp;
            if (MAP[j][i] != MAP[j + 1][i]) {
                tmp = MAP[j][i];
                MAP[j][i] = MAP[j + 1][i];
                MAP[j + 1][i] = tmp;

                // 가장 긴 연속 부분 찾기
                max_len();

                char tmp2;
                tmp2 = MAP[j][i];
                MAP[j][i] = MAP[j + 1][i];
                MAP[j + 1][i] = tmp2;
            }
        }
    }
}

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); j++) {
            MAP[i][j] = str[j];
        }
    }
}

void solv() {
    input();

    max_len();
    search_col();
    search_row();
}

int main() {

    solv();
    cout << maxCnt << "\n";

    return 0;
}