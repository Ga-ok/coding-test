#include <iostream>
using namespace std;

int boys[10];

int main() {

	for (int i = 0; i < 9; i++) {
		int height;
		cin >> height;
		boys[i] = height;
	}

	int temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boys[j] > boys[j+1]) {
				temp = boys[j];
				boys[j] = boys[j + 1];
				boys[j + 1] = temp;
			}
		}
	}

	int flag = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			int result = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				result += boys[k];
			}
			if (result == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << boys[k] << "\n";
				}
				flag = 1;
				break;
			}
		}

		if (flag == 1) break;
	}

	return 0;
}