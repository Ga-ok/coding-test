#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[n - 1];

	return 0;
}