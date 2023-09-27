#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int k;  cin >> k;
    
    int dp[46][2];
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    
    for(int i=3; i<=k; i++){
        int a = dp[i-1][0];
        int b = dp[i-1][1];
        dp[i][0] = b;
        dp[i][1] = a+b; 
    }
    
    cout << dp[k][0] << " " << dp[k][1];

    return 0;
}
