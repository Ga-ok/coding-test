#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int to;
	int cost;
};

bool operator <(Node a, Node b) {
	if (a.cost > b.cost) return true;
	if (a.cost < b.cost)return false;
	if (a.to > b.to) return true;
	if (a.to < b.to) return false;
	return false;
}

int main() {

	int n;
	int m;
	cin >> n >> m;

	vector<Node> v[1001];
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}

	int start, end;
	cin >> start >> end;


	// 필요한 값 세팅
	int dist[1001];
	int visited[1001] = { 0 };
	priority_queue<Node> pq;

	// 초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = 2134567890;
	}
	dist[start] = 0;
	pq.push({ start, 0 });


	// 다익스트라
	while (!pq.empty()) {
		int now = pq.top().to;
		int nowCost = pq.top().cost;
		pq.pop();

		if (visited[now] != 0) continue;
		visited[now] = 1;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].to;
			int nextCost = v[now][i].cost;

			if (dist[now] + nextCost > dist[next]) continue;
			dist[next] = dist[now] + nextCost;
			pq.push({ next, dist[next] });
		}
	}

	cout << dist[end];

	return 0;
}