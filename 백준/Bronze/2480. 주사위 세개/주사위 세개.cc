#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b== c) {
		cout << a * 1000 + 10000;
	}
	else if (a == b || b == c || a == c) {
		int val = 0;
		if (a == b)val = a;
		else if (b == c)val = b;
		else val = c;

		cout << 1000 + val * 100;
	}
	else {
		int max = a;
		if (max < b) max = b;
		if (max < c) max = c;
		cout << max * 100;
	}

	return 0;
}



