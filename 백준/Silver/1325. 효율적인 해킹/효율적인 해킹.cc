#include <iostream>
#include <vector>
using namespace std;

vector<int> v[10001];
int DAT[10001];
int visited[10001];

int cnt = 0;
void dfs(int node) {

	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (visited[next] != 0) continue;
		cnt += 1;
		visited[next] = 1;
		dfs(next);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int to, from;
		cin >> to >> from;
		v[from].push_back(to);
	}

	int maxCnt = 0;
	for (int i = 1; i <= n; i++) {
		visited[i] = 1;
		dfs(i);
		DAT[i] = cnt;

		if (maxCnt < cnt) maxCnt = cnt;
		cnt = 0;
		for (int i = 1; i <= n; i++) visited[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (DAT[i] == maxCnt) cout << i << " ";
	}

	return 0;
}