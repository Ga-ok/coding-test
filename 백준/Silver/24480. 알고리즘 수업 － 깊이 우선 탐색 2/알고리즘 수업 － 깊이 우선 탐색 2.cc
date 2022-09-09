#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100001];
int visited[100001];
int DAT[100001];
int n = 1;
void dfs(int node) {

	
	sort(v[node].begin(), v[node].end(), greater<int>());

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];

		if (visited[next] != 0) continue;
		visited[next] = 1;

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

	visited[r] = 1;
	DAT[r] = 1;
	dfs(r);

	for (int i = 1; i <= n; i++) {
		cout << DAT[i] << "\n";
	}
	
	return 0;
}
