#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];

int main(){
    cin >> N;
    
    int r, g, b;
    for(int i=1; i<=N; i++){
        cin >> r >> g >> b;
        
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
    }
    
    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
    
    return 0;
}