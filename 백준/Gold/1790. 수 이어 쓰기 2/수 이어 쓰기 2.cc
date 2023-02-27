#include <iostream>
#include <string>
using namespace std;

int N, K;
int cnt;
void findNumber() {
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.length(); j++) {
			cnt += 1;
			if (cnt == K) {
				cout<<str[j];
				return;
			}
		}
		if (cnt == K) {
			cout<<str[0];
			return;
		}
	}

	if (cnt < K) cout<<"-1";
	return;
}


int main() {

	cin >> N >> K;
	findNumber();

	return 0;
}