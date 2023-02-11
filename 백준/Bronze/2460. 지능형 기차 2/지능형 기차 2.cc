#include <iostream>
using namespace std;

int main() {
	int ing = 0;
	int max = 0;

	for (int i = 1; i <= 10; i++) {
		int out, in;
		cin >> out >> in;
		
		ing = ing - out + in;
		if (max < ing) {
			max = ing;
		}
	}

	cout << max;

	return 0;
}