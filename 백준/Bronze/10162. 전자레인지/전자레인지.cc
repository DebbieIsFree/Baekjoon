#include <iostream>
using namespace std;

int main() {
	int T;	cin >> T;
	int Acnt = 0, Bcnt = 0, Ccnt = 0;

	if (300 <= T) {
		Acnt += T / 300;
		T = T % 300;
	}
	if (60 <= T) {
		Bcnt += T / 60;
		T = T % 60;
	}
	if (10 <= T) {
		Ccnt += T / 10;
		T = T % 10;
	}

	if (T > 0)
		cout << "-1";
	else
		cout << Acnt << ' ' << Bcnt << ' ' << Ccnt;

	return 0;
}