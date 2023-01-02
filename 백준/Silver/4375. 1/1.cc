#include <iostream>

using namespace std;

int main() {

	int n;
	while (cin >> n) {

		int k = 0;
		for (int i = 1;; i++) {

			k = (k * 10 + 1) % n;

			if (k == 0) {
				cout << i << "\n";
				break;
			}
			
		}
		
	}

	return 0;
}