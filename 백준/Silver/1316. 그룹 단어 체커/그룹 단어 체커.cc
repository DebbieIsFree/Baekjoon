#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;	cin >> n;
	cin.ignore();

	int count = n; 

	while (n--) {
		string s;
		cin >> s;

		int arr[26] = { 0, };

		int i = 0;
		while (i < s.size()) {
			int tmp = (int)(s[i]) - 97;		// int tmp = s[i] - '0' 하면 에러 뜸


			if (arr[tmp] != 0) {		// 이전에 나온 알파벳 (검증)
				if (s[i] == s[i - 1]) {
					arr[tmp] += 1;
					i++;
				}
				else { 
					count--;
					break; 
				}
			}

			else if (arr[tmp] == 0) {		// 처음 나온 알파벳
				arr[tmp] += 1;
				i++;
			}
		}
	}

	cout << count;

	return 0;
}
