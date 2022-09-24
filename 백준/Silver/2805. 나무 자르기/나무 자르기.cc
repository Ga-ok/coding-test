#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long parametric_search(vector<long long>& trees, long long target) {

	long long left = 0;
	long long right = trees[trees.size() - 1];

	long long maxHeight = 0;
	while (left <= right) {

		long long mid = (left + right) / 2;
		long long sumHeight = 0;
		
		for (int i = 0; i < trees.size(); i++) {
			if (trees[i] > mid) sumHeight += (trees[i] - mid);
		}

		if (sumHeight < target) {
			right = mid - 1;
		}
		else {
			maxHeight = mid;
			left = mid + 1;
		}
	}
	return maxHeight;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long long> trees;
	for (int i = 0; i < n; i++) {
		long long tree;
		cin >> tree;

		trees.push_back(tree);
	}

	sort(trees.begin(), trees.end());

	cout<<parametric_search(trees, m);

	return 0;
}