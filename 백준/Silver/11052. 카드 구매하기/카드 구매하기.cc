#include <iostream>
using namespace std;

// F[A] = B 
// A장의 카드를 사는데 지불해야 하는 최대 금액은 B원
	
int Pay[1001];
int DP[1001];

int main() {
	int N;	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> Pay[i];
	}
	
	DP[1] = Pay[1];

	// i + j = N의 조합 -> 여러 개 
	// ex) 1+3 == 2+2 == 4
	for (int i = 2; i <= N; i++) {
		DP[i] = Pay[i];
		for (int j = 1; j < i; j++) {
			DP[i] = max(DP[i], DP[j] + DP[i - j]);
		}
	}

	cout << DP[N];

	return 0;
}