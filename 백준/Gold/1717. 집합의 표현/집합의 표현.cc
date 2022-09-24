#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int parent[1000001];

int Find(int now) {
	if (parent[now] == now) return now;
	int root = Find(parent[now]);

	parent[now] = root;
	return root;
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	parent[pb] = pa;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 1000001; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0) {
			Union(b, c);
		}

		else if (a == 1) {
			if (Find(b) == Find(c)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}