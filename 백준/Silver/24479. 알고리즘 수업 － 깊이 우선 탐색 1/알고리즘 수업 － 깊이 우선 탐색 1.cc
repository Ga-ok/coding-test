#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int visited[100001];
int DAT[100001];
//vector<int> path;
int n = 1;
void dfs(int node) {

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];

		if (visited[next] != 0) continue;
		visited[next] = 1;

		//path.push_back(next);
		n++;
		DAT[next] = n;
		dfs(next);
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

	for (int i = 0; i < n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	visited[r] = 1;
	DAT[r] = 1;
	dfs(r);

	/*for (int i = 0; i < path.size(); i++) {
		cout << path[i] << "\n";
	}

	while (path.size() != n) {
		cout << 0 << "\n";
		path.push_back(0);
	}
	*/

	for (int i = 1; i <= n; i++) {
		cout << DAT[i] << "\n";
	}
	
	return 0;
}