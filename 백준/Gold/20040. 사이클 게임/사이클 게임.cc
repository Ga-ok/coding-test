#include <iostream>

using namespace std;
int parent[500001];

int find(int root) {
	if (parent[root] == root) return root;
	return parent[root] = find(parent[root]);
}

void Union(int a, int b) {
	a = find(parent[a]);
	b = find(parent[b]);

	if (a == b) return;
	parent[b] = a;
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