#include <iostream>
using namespace std;

int main() {
	//char map[8][8];
	int cnt = 0;

 	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char input; cin >> input;
			if (i % 2 == 0 && j % 2 == 0) {
				if (input == 'F') cnt++;
			}
			else if(i % 2 == 1 && j % 2 == 1) {
				if (input == 'F') cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}