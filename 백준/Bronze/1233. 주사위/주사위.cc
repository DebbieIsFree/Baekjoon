#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int check[81] = { 0, };
	int s1 = 0, s2 = 0, s3 = 0;
	cin >> s1 >> s2 >> s3;

	for (int L1 = 1; L1 <= s1; L1++) {
		for (int L2 = 1; L2 <= s2; L2++) {
			for (int L3 = 1; L3 <= s3; L3++) {
				check[L1 + L2 + L3] += 1;
			}
		}
	}

	int maxValue = *max_element(check, check+81);

	for(int i = 1; i <= 80; i++) {
		if (check[i] == maxValue)
		{
			cout << i;
			break;
		}
	}

	return 0;
}