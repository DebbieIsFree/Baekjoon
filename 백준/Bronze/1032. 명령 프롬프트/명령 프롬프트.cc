#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;	cin >> N;
	string str1;	cin >> str1;
	string result = str1;

	N -= 1;
	while (N--) {
		string tmp;	cin >> tmp;
		string res = "";

		for (int i = 0; i < tmp.length(); i++) {
			if (result[i] == tmp[i]) {
				res += tmp[i];
			}
			else {
				res += "?";
			}
		}

		if (res.length() <= result.length()) {
			result = res;
		}
	}

	cout << result;

	return 0;
}