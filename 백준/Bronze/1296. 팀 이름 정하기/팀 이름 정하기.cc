#include <iostream>
#include <string>

using namespace std;



int main() {
	string tmp;	cin >> tmp;
	int n;	cin >> n;
	string result = "";
	int max = 0;
	int cnt[4] = { 0,0,0,0 };
	bool flag = false;

	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == 'L')cnt[0] += 1;
		else if (tmp[i] == 'O')cnt[1] += 1;
		else if (tmp[i] == 'V')cnt[2] += 1;
		else if (tmp[i] == 'E')cnt[3] += 1;
	}

	if (n == 1) {
		string name;	cin >> name;
		result = name;
		cout << name;
		return 0;
	}

	while (n--) {
		string name;
		cin >> name;
		
		int l = cnt[0], o = cnt[1], v = cnt[2], e = cnt[3];

		for (int i = 0; i < name.size(); i++) {
			if (name[i] == 'L') l += 1;
			else if (name[i] == 'O') o += 1;
			else if (name[i] == 'V') v += 1;
			else if (name[i] == 'E') e += 1;
		}

		int cal = ((l + o) * (l + v) * (l + e) *
			(o + v) * (o + e) * (v + e)) % 100;

		if (!flag) {
			if (max == 0 && cal == 0) {
				result = name;
				flag = true;
			}
		}

		if (max < cal) {
			max = cal;
			result = name;
		}
		else if (max == cal) { 
			int res = result.compare(name);
			if (res > 0) result = name;
		}
	}
	cout << result;

	return 0;
}