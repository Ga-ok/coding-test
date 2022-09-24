#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;

	int b;
	cin >> b;

	vector<char> answer;
	while (n > 1) {

		int div = n % b;
		n = n / b;

		if (div >= 10) {
			char temp = (div-10)+'A';
			div = temp;
			answer.push_back(div);
		}
		else {
			answer.push_back(div + '0');
		}
	}

	if (n == 1) {
		answer.push_back(n + '0');
	}
	

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i];
	}
	

	return 0;
}