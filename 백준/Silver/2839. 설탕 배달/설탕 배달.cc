#include <iostream>

using namespace std;

int main() {
	int N;	cin >> N;	
	int t = N / 5;			
	
	while (t >= 0) {
		int remainder = N - (5 * t);

		if (remainder % 3 == 0) {
			cout << t + (remainder / 3);
			break;
		}
		else {
			t--;	
			if (t < 0) {		
				cout << "-1" << "\n";
				break;
			}
		}

	}
}

