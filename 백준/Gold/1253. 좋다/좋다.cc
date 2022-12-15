#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> numbers;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	int res = 0;
	for (int i = 0; i < n; i++) {
		
		int target = numbers[i];

		int l = 0;
		int r = n - 1;

		while (l < r) {

			int sum = numbers[l] + numbers[r];	

			if (sum == target) {
				if (r != i && l != i) {
					res++;
					break;
				}
				if (l == i) l++;
				if (r == i) r--;
			}
			else if (sum < target) l++;
			else r--;
		}
	}

	cout << res;

	return 0;
}