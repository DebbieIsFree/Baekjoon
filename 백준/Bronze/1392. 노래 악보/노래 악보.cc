#include <iostream>
using namespace std;


int main() {
	int time[9999] = {};
	int N, Q;
	cin >> N >> Q;
	int sec = 0;

	for (int i = 1; i <= N; i++) {
		int t;	cin >> t;
		for (int h = sec; h < sec + t; h++) {
			time[h] = i;
		}
		sec += t;
	}

	for (int i = 1; i <= Q; i++) {
		int q;	cin >> q;
		cout << time[q] << "\n";
	}


	return 0;
}