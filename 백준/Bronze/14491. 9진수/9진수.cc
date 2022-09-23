#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;

	string res = "";
	while (n >= 9) {

		int div = n % 9;
		res += (div + '0');
		n = n / 9;
	}

	res += (n + '0');
	
	for (int i = res.length() - 1; i >= 0; i--) {
		cout << res[i];
	}

	return 0;
}