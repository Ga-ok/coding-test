#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	pair<int, int> person[51];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		person[i].first = x;
		person[i].second = y;
	}

	int rank = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (person[i].first < person[j].first && person[i].second < person[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
		rank = 1;
	}

	return 0;
}