#include <iostream>
#include <vector>
using namespace std;

int main() {

	for (int i = 2; i <= 100; i++) {
		int a = i * i * i;

		for (int j = 2; j <= 100; j++) {
			int b = j * j * j;
			for (int k = j+1; k <= 100; k++) {
				int c = k * k * k;
				for (int l = k+1; l <= 100; l++) {
					int d = l * l * l;
					if (a == (b + c + d)) {
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
					}
				}
			}
		}
	}

	return 0;
}