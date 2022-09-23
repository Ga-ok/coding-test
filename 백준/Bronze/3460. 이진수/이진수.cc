#include <iostream>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; testcase++) {

		int n;
		cin >> n;

		string res = "";
		while (n > 1) {
			int div = n % 2;
			res += (div + '0');

			n = n / 2;
		}

		res += (n + '0');

		string reverseRes = "";

		for (int i = 0; i < res.length(); i++) {
			if (res[i] == '1') cout << i << " ";
		}
		cout << "\n";
	}

	
	

	return 0;
}