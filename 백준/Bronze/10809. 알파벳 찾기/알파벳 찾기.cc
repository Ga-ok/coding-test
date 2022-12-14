#include <iostream>
#include <string>
using namespace std;

int DAT[26];
int main() {

	for (int i = 0; i < 26; i++) {
		DAT[i] = -1;
	}

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		int index = str[i] - 'a';
		if (DAT[index] != -1) continue;
		DAT[index] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << DAT[i] << " ";
	}

	return 0;
}