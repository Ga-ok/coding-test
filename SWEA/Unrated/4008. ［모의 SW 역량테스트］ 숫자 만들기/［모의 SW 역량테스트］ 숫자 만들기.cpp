#include <iostream>
#include <vector>
using namespace std;

int idx;
vector<string> opp;
vector<int> opp_num;
vector<int> number;

int visited[12];

int maxRes = -2134567890;
int minRes = 2134567890;
int calc(int num1, int num2, int op) {
	if (op == 0) return num1 + num2;
	else if (op == 1) return num1 - num2;
	else if (op == 2) return num1 * num2;
	else if (op == 3) return num1 / num2;
}

void dfs(int level, int res) {

	if (level == idx) {

		if (maxRes < res) {
			maxRes = res;
		}
		if (minRes > res) {
			minRes = res;
		}

		return;
	}

	for (int i = 0; i < opp_num.size(); i++) {
		
		if (opp_num[i] == 0) continue;
		opp_num[i]-=1;

		if (level == 0) {
			int temp = calc(number[level], number[level + 1], i);
			dfs(level + 1, temp);
		}
		else {
			int temp = calc(res, number[level + 1], i);
			dfs(level + 1, temp);
		}
		
		opp_num[i] += 1;
	}

}

int main() {

	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		cin >> n;

		for (int i = 0; i < 4; i++) {
			int temp;
			cin >> temp;
			opp_num.push_back(temp);
			idx+=temp;
		}
		
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			number.push_back(num);
		}
        
		dfs(0, 0);
		cout << "#"<<testcase<<" "<<maxRes - minRes<<"\n";

		maxRes = -2134567890;
		minRes = 2134567890;

		number.clear();
		opp_num.clear();
        idx=0;
		
	}

	return 0;
}