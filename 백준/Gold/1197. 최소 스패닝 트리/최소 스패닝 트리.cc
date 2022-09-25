#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int from;
	int to;
	int cost;
};


bool cmp(Edge a, Edge b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
}

int parent[10001];

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
	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	vector<Edge> edges;
	for (int i = 0; i < E; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}

	sort(edges.begin(), edges.end(), cmp);

	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {

		int from = edges[i].from;
		int to = edges[i].to;

		if (Find(from) == Find(to)) continue;

		Union(from, to);
		sum += edges[i].cost;

	}

	cout << sum;

	return 0;
}