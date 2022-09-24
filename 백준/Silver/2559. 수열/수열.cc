#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> temp;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		temp.push_back(t);
	}

	int left = 0;
	int right = k-1;

	int sum = 0;
	for (int i = left; i < right; i++) {
		sum += temp[i];
	}

	int maxSum = -2134567890;
	while (right < n) {

		sum += temp[right];

		if (maxSum < sum) maxSum = sum;

		sum -= temp[left];
		right++;
		left++;
	}

	cout << maxSum;

	return 0;
}