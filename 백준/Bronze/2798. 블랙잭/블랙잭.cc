#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> card;
int visited[100001];
int maxResult = -2134567890;
void dfs(int level, int result) {

	if (result > m) return;
	if (level == 3) {
		if (maxResult < result) maxResult = result;
		return;
	}

	for (int i = 0; i < card.size(); i++) {
		if (visited[card[i]] != 0) continue;
		visited[card[i]] = 1;
		dfs(level + 1, result+card[i]);
		visited[card[i]] = 0;
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		card.push_back(number);
	}

	dfs(0, 0);
	
	cout << maxResult;
	return 0;
}