#include <iostream>
using namespace std;

int people[15][15];

int main() {
	int T;	cin >> T;

	for (int i = 1; i <= 14; i++) {
		people[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			if (j == 1) {
				people[i][j] = people[i - 1][j];
			}
			else {
				people[i][j] = people[i][j - 1] + people[i - 1][j];
			}
		}
	}

	while (T--) {
		int k, n;
		cin >> k;
		cin >> n;

		cout << people[k][n] << endl;
	}

	return 0;
}









