#include <iostream>
#include <string>
using namespace std;

int n;
int maxSum = -2134567890;  // **�����Ұ�! 0���� �ϸ� �ȵȴ� �Ф� 
string str;

int calculate(int a, int b, char op) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void dfs(int idx, int sum) {
	
	// ��������
	if (idx > n - 1) {
		if (sum > maxSum) maxSum = sum;
		return;
	}

	char op;
	int tmp;

	// ��ȣ �߰����� �ʴ� ���
	if (idx == 0) op = '+';
	else op = str[idx - 1];

	// ������ ��(sum=0)�� tmp���� �� ����
	dfs(idx + 2, calculate(sum, str[idx] - '0', op));


	// ��ȣ �߰��ϴ� ���
	if (idx + 2 < n) {

		int value1 = str[idx] - '0';
		int value2 = str[idx + 2] - '0';

		tmp = calculate(value1, value2, str[idx + 1]);
		// ������ ��(sum=0)�� tmp���� �� ����
		dfs(idx + 4, calculate(sum, tmp, op));
	}
}

int main() {
	
	cin >> n;
	cin >> str;

	dfs(0, 0);
	cout << maxSum;
	return 0;
}