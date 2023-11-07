#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;	cin >> t;

	while (t--) {
		int num;	cin >> num;
		int room[101] = { 0, };		// 1라운드 : 모두 open 

		for (int i = 2; i <= num; i++) {
			for (int j = 1; i*j <= num; j++) {
				room[i * j] = !room[i * j];
			}
		}
		cout << count(room+1, room + num+1, 0) << "\n";
	}

	return 0;
}