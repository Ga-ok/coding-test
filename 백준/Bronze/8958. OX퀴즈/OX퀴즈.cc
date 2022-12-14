#include <iostream>
#include <string>
using namespace std;

int main() {

	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; testcase++) {
		string str;
		cin >> str;

		int res = 0;
		int point = 1;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'O') {
				res += point;
				point++;
			}
			else {
				point = 1;
			}
		}
		cout << res << "\n";
	}

	return 0;
}