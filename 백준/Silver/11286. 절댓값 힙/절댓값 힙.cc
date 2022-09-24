#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) return true;
		if (abs(a) < abs(b)) return false;
		if (a > b) return true;
		if (a < b) return false;
		return false;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x != 0) {
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