#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;

	int result = 0;
	int k = 0;
	for (int i = str.size()-1; i >= 0; i--) {
		int n = str[i] - '0';
		if (n >= 10) {
			n = 10 + (str[i] - 'A');
		}
		
		int temp = 1;
		for (int j = 0; j < k; j++) {
			temp *= 16;
		}

		result += (n * temp);
		k++;
	}

	cout << result;

	return 0;
}