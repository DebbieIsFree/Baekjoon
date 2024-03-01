#include <iostream>
#include <queue>
using namespace std;

// boj 1158 (요세푸스 순열)   
// shadowing  :  https://parkssiss.tistory.com/81 


int main() {
	queue <int> q;

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		q.push(i + 1);

	cout << '<';

	while (!q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		if (q.size() == 1) cout << q.front();
		else cout << q.front() << ", ";

		q.pop();

	}

	cout << '>';
}