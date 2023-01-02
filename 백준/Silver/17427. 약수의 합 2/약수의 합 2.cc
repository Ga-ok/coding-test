#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long res = 0;
	for (int i = 1; i <= n; i++) {
		int num = n / i;
		res += (num * i);
	}

	cout << res << "\n";

	return 0;
}