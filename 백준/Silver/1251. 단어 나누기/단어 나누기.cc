#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	string str;		cin >> str;
	priority_queue<string, vector<string>, greater<string>> q;
	//queue<string> q;
		
	string s1 = "", s2 = "", s3 = "";
	for (int fir = 0; fir <= str.length() - 3; fir++) {
		s1 += str[fir];
		for (int sec = fir+1; sec <= str.length() - 2; sec++) {
			s2 += str[sec];
			for (int thir = sec+1; thir <= str.length() - 1; thir++) {
				s3 += str[thir];
			}
			//cout << s1 + " " + s2 + " " + s3 << " : ";
			string tmp1 = s1, tmp2 = s2, tmp3 = s3;
			reverse(tmp1.begin(), tmp1.end());
			reverse(tmp2.begin(), tmp2.end());
			reverse(tmp3.begin(), tmp3.end());
			string input = tmp1 + tmp2 + tmp3 ;
			//cout << input << endl;
			q.push(input);
			s3 = "";
		}
		s2 = "";
	}


	/*while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}*/

	cout << q.top();

	return 0;
}



