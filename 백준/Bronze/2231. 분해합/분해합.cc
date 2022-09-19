#include <iostream>

using namespace std;

int solution(int n) {

	int result = n;

	while (n >= 10) {
		int temp = n % 10;
		n = n / 10;

		result += temp;
	}
	
	result += n;
	return result;
}

int main() {

	int n;
	cin >> n;

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		int res = solution(i);
		if (n == res) {
			cout << i;
			flag = 1;
			break;
		}
	}

	if (flag == 0) cout << 0;

	return 0;
}