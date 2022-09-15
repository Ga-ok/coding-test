#include <iostream>
#include <vector>
using namespace std;

vector<int> v[500001];
int visited[500001];

int cnt = 0;
void dfs(int node, int level) {

	if (node != 1 && v[node].size() == 1) {
		if (level % 2 == 1) cnt += 1;
		return;
	}

	for (int i = 0; i < v[node].size(); i++) {

		if (visited[v[node][i]] != 0) continue;
		visited[v[node][i]] = 1;
		dfs(v[node][i], level + 1);
		visited[v[node][i]] = 0;
	}

}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	visited[1] = 1;
	dfs(1, 0);

	if (cnt % 2 == 1) cout << "Yes";
	else cout << "No";

	return 0;
}