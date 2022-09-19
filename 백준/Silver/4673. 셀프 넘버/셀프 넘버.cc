#include <iostream>
#include <vector>
using namespace std;

int DAT[10001];
int d(int n) {
	
	int result = n;
	
	while (n >= 10) {
		int div = n % 10;
		n = n / 10;

		result += div;
	}

	result += n;
	return result;
}

int main() {

	vector<int> ans;

	for (int i = 0; i <= 10000; i++) {
		int res = d(i);
		DAT[res] = 1;
	}


	for (int i = 0; i <= 10000; i++) {
		if (DAT[i] != 0) continue;
		cout << i << "\n";
	}
	

	return 0;
}