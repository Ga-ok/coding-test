#include <iostream>

using namespace std;

int jun;
int sung;
int stock[14];

int junCnt = 0;
int sungCnt = 0;

void junplay() {

	for (int i = 0; i < 14; i++) {

		if (jun < stock[i]) continue;

		junCnt += jun / stock[i];
		jun = jun % stock[i];

	}
}

void sungplay() {

	int stockFlow[14];
	for (int i = 0; i < 14; i++) {
		if (i == 0) {
			stockFlow[i] = stock[i];
			continue;
		}

		stockFlow[i] = (stock[i] - stock[i - 1]);
	}

	int upCnt = 0;
	int downCnt = 0;
	for (int i = 1; i < 14; i++) {
		if (stockFlow[i] > 0) {
			upCnt += 1;
			downCnt = 0;
		}
		if (stockFlow[i] < 0) {
			downCnt += 1;
			upCnt = 0;
		}

		if (upCnt == 3) {
			sung += (sungCnt * stock[i]);
			upCnt = 0;
			downCnt = 0;
		}

		if (downCnt == 3) {
			sungCnt += sung / stock[i];
			sung = sung % stock[i];

			upCnt = 0;
			downCnt = 0;
		}
	}

}

int main() {
	int money;
	cin >> money;

	jun = money;
	sung = money;

	for (int i = 0; i < 14; i++) {
		cin >> stock[i];
	}

	junplay();
	sungplay();

	jun = jun + (stock[13] * junCnt);
	sung = sung + (stock[13] * sungCnt);
	if (jun > sung) cout << "BNP";
	else if (jun < sung) cout << "TIMING";
	else if (jun == sung) cout << "SAMESAME";

	//cout << junCnt << " " << jun + (stock[13] * junCnt);
	//cout << sungCnt << " " << sung + (stock[13] * sungCnt);

	return 0;
}