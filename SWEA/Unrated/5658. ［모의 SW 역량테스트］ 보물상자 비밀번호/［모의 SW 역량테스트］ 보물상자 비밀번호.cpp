#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque<char> dq;
vector<long long> numbers;

long long stringToInt(string str) {

	long long res = 0;
	int temp = 0;
	for (int i = str.size() - 1; i >= 0; i--) {

		int num = 1;
		for (int j = 0; j < temp; j++) {
			num *= 16;
		}

		if (temp == 0) {
			char target = str[i];
			if (target >= '0' && target <= '9') res += (target - '0');
			else {
				res += ((target - 'A') + 10);
			}
		}
		else{
			char target = str[i];
			if (target >= '0' && target <= '9') res += num*(target - '0');
			else {
				res += num*((target - 'A') + 10);
			}
		}
		temp++;
	}
	
	return res;
}

int main() {

	int t;
	cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {
		int n, k;
		cin >> n >> k;

		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			dq.push_back(str[i]);
		}

		for (int j = 0; j < n; j++) {

			str = "";
			for (int i = 0; i < dq.size(); i++) {
				str += dq[i];
			}
			
			string temp;
			for (int i = 0; i < str.length(); i = i + n / 4) {
				temp = str.substr(i, n / 4);
				long long num = stringToInt(temp);

				numbers.push_back(num);
				//cout << temp << " ";
			}
			//cout << "\n";

			char temp2 = dq.back();
			dq.pop_back();
			dq.push_front(temp2);

			
		}
		
		sort(numbers.begin(), numbers.end(), greater<long long> ());
		numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
		
		/*for (int i = 0; i < numbers.size()-1; i++) {
			cout << numbers[i] << " ";
		}
		cout << "\n";*/
		cout << "#" << testcase <<" "<<numbers[k-1] << "\n";

		dq.clear();
		numbers.clear();

	}

	return 0;
}