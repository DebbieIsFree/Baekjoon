#include <iostream>
using namespace std;

long long int arr[81];	// Find[N]의 값을 저장

// 다이나믹 프로그래밍
long long int Find(int N) {		// DP - Top Down 방식 (메모이제이션) --> 좀 더 연습하기
	if (N == 1) return arr[1];
	if (N == 2) return arr[2];

	if (arr[N]) {
		return arr[N];
	}
	arr[N] = Find(N - 1) + Find(N - 2);		// arr[N-1] + arr[N-2] 라고 써서 틀렸음
	return arr[N];
}

int main() {
	int N;
	cin >> N;

	arr[1] = 4;
	arr[2] = 6;

	cout << Find(N);

	return 0;
}