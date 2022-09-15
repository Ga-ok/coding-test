#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; testcase++) {

		int n, m;
		cin >> n >> m;

		int cnt = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((i * i + j * j + m) % (i * j) == 0) cnt += 1;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}