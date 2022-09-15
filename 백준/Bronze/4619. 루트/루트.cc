#include <iostream>
#include <vector>
using namespace std;

int main() {

	while (1) {

		int b, n;
		cin >> b >> n;

		if (b == 0 && n == 0) break;

		int num = 0;
		int minSub = 1000000;
		for (int i = 1; i <= b; i++) {

			int temp=1;
			for (int j = 0; j < n; j++) {
				temp *= i;
			}

			if (abs(b - temp) <= minSub) {
				minSub = abs(b - temp);
				num = i;
			}
			else break;
		}

		cout << num << " ";

	}

	return 0;
}