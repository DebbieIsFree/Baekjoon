#include <iostream>
using namespace std;

int map[501][501];
int dp[501][501];
bool visited[501][501];

int main() {
	int n;	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[1][1];
	visited[1][1] = true;

	for (int i = 1; i <= n-1; i++) {		
		for (int j = 1; j <= i+1; j++) {		
			if (!visited[i + 1][j]) {
				dp[i + 1][j] = dp[i][j] + map[i + 1][j];
				visited[i + 1][j] = true;
			}
			else {
				int preVal = dp[i + 1][j];
				int newVal = dp[i][j] + map[i+1][j];
				if(preVal < newVal)
					dp[i + 1][j] = newVal;
			}
			if (!visited[i + 1][j+1]) {
				dp[i + 1][j+1] = dp[i][j] + map[i + 1][j+1];
				visited[i + 1][j+1] = true;
			}
			else {
				int preVal = dp[i + 1][j+1];
				int newVal = dp[i][j] + map[i+1][j+1];
				if (preVal < newVal)
					dp[i + 1][j + 1] = newVal;
			}
		}
	} 


	// checking 
	/*cout << endl << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i]) {
			max = dp[n][i];
		}
	}
	
	cout << max;

	return 0;
}



// 1행 증가 -> 
// 행 증가 & 같은 열 
// or
// 행 증가 & 열 +1 증가





