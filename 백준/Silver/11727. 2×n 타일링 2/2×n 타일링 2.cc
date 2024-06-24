#include <iostream>
using namespace std;

int N;
int dp[1001];

int main(){
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 3;
    
    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + (dp[i-2] * 2)) % 10007;        // *3이 아닌 이유는, [i-1]과 [i-2]에서 겹치는(동일한) 부분이 있다.
    }
    
    cout << dp[N];

    return 0;
}