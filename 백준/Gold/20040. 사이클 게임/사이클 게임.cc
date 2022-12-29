#include <iostream>

using namespace std;
int parent[500001];

int find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = find(parent[now]);
}

void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return;
	parent[pb] = pa;
}

int main() {

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b)) {
			cout << i + 1;
			return 0;
		}
		Union(a, b);
	}
	cout << 0;

	return 0;
}