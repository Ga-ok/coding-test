#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int visited[100001];
int DAT[100001];
void dfs(int node, int level) {

	sort(v[node].begin(), v[node].end(), less<int>());

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];

		if (visited[next] != 0) continue;
		visited[next] = 1;

		DAT[next] = level+1;
		dfs(next, level+1);
	}

}

int main() {

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		DAT[i] = -1;
	}

	visited[r] = 1;
	DAT[r] = 0;
	dfs(r, 0);

	for (int i = 1; i <= n; i++) {
		cout << DAT[i] << "\n";
	}
	
	return 0;
}
