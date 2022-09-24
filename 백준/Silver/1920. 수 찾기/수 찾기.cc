#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void binary_search(vector<int> &numbers, int target) {

	int left = 0;
	int right = numbers.size() - 1;
	
	while(left <= right) {

		int mid = (left + right) / 2;

		if (numbers[mid] == target) {
			cout << "1\n";
			return ;
		}

		else if (numbers[mid] < target) {
			left = mid + 1;
		}

		else if(numbers[mid] > target){
			right = mid - 1;
		}

	}

	cout << "0\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		binary_search(numbers, num);
		
	}

	return 0;
}