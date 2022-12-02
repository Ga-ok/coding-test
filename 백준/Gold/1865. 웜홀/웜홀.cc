#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int s;
	int e;
	int t;
};

int n, m, w;  // n: 지점 m: 도로 w: 웜홀
vector<Edge> edges;

bool move() {

	vector<int> dist(n + 1);

	dist[1] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int s = edges[j].s;
			int e = edges[j].e;
			int t = edges[j].t;

			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}

	for (int j = 0; j < edges.size(); j++) {
		int s = edges[j].s;
		int e = edges[j].e;
		int t = edges[j].t;

		if (dist[e] > dist[s] + t) {
			return true; // 음수 사이클 존재(한번 더 돌려서 갱신되는 수가 있다면)
		}
	}

	return false;
}


int main() {

	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; testcase++) {
		
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int s, e, t; // s-e 연결된 지점의 번호 t: 걸리는 시간
			cin >> s >> e >> t; 
			edges.push_back({ s, e, t });
			edges.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++) {
			int s, e, t;  // s-e 연결된 지점의 번호 t: 줄어드는 시간
			cin >> s >> e >> t;
			edges.push_back({ s, e, -t });
		}

		bool res = move();
		if (res) cout << "YES\n";
		else cout << "NO\n";

		edges.clear();
	}

	return 0;
}