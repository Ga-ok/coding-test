#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			if (i * i == j * j + n) cnt += 1;
		}
	}

	cout << cnt;

	return 0;
}