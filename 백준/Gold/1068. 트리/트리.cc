#include <iostream>
#include <vector>
using namespace std;

int root;
vector<int> tree[51]; // parent, child
int visited[51];
int target;
int cnt = 0;
void dfs(int now) {

	if (now == target) return;
	if (tree[now].size() == 0) {
		cnt++;
		return;
	}

	for (int i = 0; i < tree[now].size(); i++) {
		if (visited[tree[now][i]] != 0) continue;

		if (tree[now][i]==target && tree[now].size() == 1) {
			cnt++;
		}
		else {
			visited[tree[now][i]] = 1;
			dfs(tree[now][i]);
			visited[tree[now][i]] = 0;
		}
	}
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == -1) {
			root = i;
		}
		else {
			tree[num].push_back(i);
		}
	}

	cin >> target;

	if (target == root) {
		cout << 0;
	}
	else {
		dfs(root);
		cout << cnt;
	}

	return 0;
}