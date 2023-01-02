#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testcase = 0;
	cin >> testcase;

	vector<long long> D(1000001, 1);
	for (int i = 2; i <= 1000000; i++) { // i를 약수로 갖는 모든 수
		for (int j = 1; i * j <= 1000000; j++) {
			D[i * j] += i;
		}
	}

	vector<long long> S(1000001);
	for (int i = 1; i <= 1000000; i++) {
		S[i] = S[i - 1] + D[i];
	}

	for (int t = 0; t < testcase; t++) {
		int n;
		cin >> n;

		cout << S[n] << "\n";
	}

	return 0;
}