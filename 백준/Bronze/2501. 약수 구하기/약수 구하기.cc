#include <iostream>
#include <vector>
using namespace std;

vector<int> divi;
int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) divi.push_back(i);
	}

	if (divi.size() < k) cout << 0;
	else cout << divi[k - 1];

	return 0;
}