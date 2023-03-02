#include <iostream>
using namespace std;

int main() {
	int T;	cin >> T;

	while (T--) {
		string str;	  cin >> str;
			cout << str[0] << str[str.size() - 1] << endl;
			/*string::iterator start = str.begin();
			string::iterator finish = str.end()-1;
			cout << *start << *finish << "\n";*/
	}


	return 0;
}



