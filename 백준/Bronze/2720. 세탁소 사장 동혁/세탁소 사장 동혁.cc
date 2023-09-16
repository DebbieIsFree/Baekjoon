#include <iostream>
using namespace std;

int main() {
	int opt[4] = { 25, 10, 5, 1 };
	int t;	cin >> t;
	

	while (t--) {
		int n;	cin >> n;

		for (int i = 0; i < 4; i++) {
			int total = 0;
			total += (int)(n / opt[i]);
			cout << total << " ";
			n = n % opt[i];
		}
		cout << "\n";
	}
	return 0;
}