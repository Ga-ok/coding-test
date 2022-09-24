#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int numbers[10001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;

	
	for (long long i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	

	long long left = 0;
	long long right = 0;

	long long sum = 0;

	int cnt = 0;
	while (right <= n) {

		if (sum == m) {
			sum += numbers[right];
			right++;
			cnt += 1;
		}
		else if (sum < m) {
			sum += numbers[right];
			right++;
			
		}
		else if (sum > m) {
			sum -= numbers[left];
			left++;
			
		}
	}

	cout << cnt;

	return 0;
}