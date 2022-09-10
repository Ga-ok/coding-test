#include <iostream>
#include <vector>
using namespace std;

int MAP[100001];
vector<int> v[100001];
int n, k;
int cnt = 0;
void dfs(int n, int level) {

	if (level == k) return;
	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];

		if (MAP[next] == 1) cnt += 1;
		dfs(next, level+1);
	}

}

int main() {

	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
	}

	for (int i = 0; i < n; i++) {
		cin >> MAP[i];
	}

	if (MAP[0] == 1) cnt += 1;
	dfs(0, 0);

	cout << cnt;

	return 0;
}