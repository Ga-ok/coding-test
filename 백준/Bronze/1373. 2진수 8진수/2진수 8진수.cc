#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	cin >> str;

	string answer = "";
	for (int i = str.length()-1; i >=0; i--) {

		string temp = "";
		for (int j = 0; j <= 2; j++) {
			if (i - j < 0) continue;
			//cout << str[i - j];
			temp += str[i - j];
		}

		// temp를 8진수로 변환
		i = i-2;
		int res = 0;
		for (int j = 0; j < temp.length(); j++) {

			int temp2 = 1;
			for (int k = 0; k < j; k++) {
				temp2 *= 2;
			}

			res += (temp[j] - '0') * temp2;
		}
		answer += (res+'0');
		
	}
	
	for (int i = answer.length() - 1; i >= 0; i--) {
		cout << answer[i];
	}

	return 0;
}