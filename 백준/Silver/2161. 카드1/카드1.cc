#include <iostream>
#include <queue>
using namespace std;



int main() {
	queue<int> que;
	int N;	cin >> N;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	bool flag = false;

	while(que.size() > 0) {
		if (!flag) {
			cout << que.front() << " ";
			que.pop();
			flag = true;
		}
		else {
			que.push(que.front());
			que.pop();
			flag = false;
		}
	}

	return 0;
}