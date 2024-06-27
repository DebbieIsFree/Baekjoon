#include <iostream>
using namespace std;

long long dp[101];

int main(){
    int T;  cin >> T;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i=4; i<=100; i++){
        dp[i] = dp[i-3] + dp[i-2];
    }
    
    while(T--){
        int N;  cin >> N;
        
        cout << dp[N] << "\n";
    }

    return 0;
}