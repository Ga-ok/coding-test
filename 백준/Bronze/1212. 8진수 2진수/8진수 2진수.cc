#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cin >> str;

	string answer = "";
	// 8진수 -> 2진수 변환
	// 1개씩 3자리 2진수로 변경
	for (int i = 0; i < str.length(); i++) {

		int n = str[i] - '0';

		string temp="";
		while (n > 1) {
			int div = n % 2;
			n = n / 2;
			temp += (div+'0');
		}
		
		temp+=(n+'0');

		while (temp.length() < 3) {
			temp += '0';
		}

		for (int j = temp.length() - 1; j >= 0; j--) {
			answer += temp[j];
		}
	}

	int flag = 0;
	int idx = 0;
	int len = answer.length();
	for (int i = 0; i < len; i++) {
		if (answer[i] == '0' && flag==0) {
			continue;
		}
		else {
			flag = 1;
			idx = i;
			break;
		}
	}

	if (flag==0 && idx==0) {
		cout << 0;
	}
	else {
		for (int i = idx; i < len; i++) {
			cout << answer[i];
		}
	}
	
	
	return 0;
}