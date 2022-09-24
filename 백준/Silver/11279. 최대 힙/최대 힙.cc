#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x > 0) {
			pq.push(x);
		}
		else {
			if (pq.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}