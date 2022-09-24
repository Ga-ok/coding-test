#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int from;
	int to;
	int cost;
};

bool cmp(Node a, Node b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
}

int parent[10001];
vector<Node> nodes;

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

	for (int i = 0; i < 10001; i++) {
		parent[i] = i;
	}

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		nodes.push_back({ a, b, c });
	}

	sort(nodes.begin(), nodes.end(), cmp);

	int result = 0;
	for (int i = 0; i < e; i++) {
		int from = nodes[i].from;
		int to = nodes[i].to;

		if (Find(from) == Find(to)) continue;
		Union(from, to);
		result += nodes[i].cost;
	}
	cout << result;

	return 0;
}