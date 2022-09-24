#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2134567890

struct Edge {
	int to;
	int cost;
};

bool operator < (Edge a, Edge b) {
	if (a.cost < b.cost) return true;
	if (a.cost > b.cost) return false;
	return false;
};

vector<Edge> edges[300001];
priority_queue<Edge> pq;
int visited[20001] = { 0 };
int dist[20001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int k;
	cin >> k;

	
	for (int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges[u].push_back({ v, w });
	}


	for (int i = 0; i < 20001; i++) {
		dist[i] = INF;
	}

	dist[k] = 0;
	pq.push({ k, 0 });

	while (!pq.empty()) {

		int now = pq.top().to;
		int nowDist = pq.top().cost;

		pq.pop();

		if (visited[now] != 0) continue;
		visited[now] = 1;

		for (int i = 0; i < edges[now].size(); i++) {
			int next = edges[now][i].to;
			int nextDist = edges[now][i].cost;

			if (dist[next] < dist[now] + nextDist) continue;
			dist[next] = dist[now] + nextDist;
			pq.push({ next, -dist[next] });
		}

	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else if (i == k) cout << 0 << "\n";
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}