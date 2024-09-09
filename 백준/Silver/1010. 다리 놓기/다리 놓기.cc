#include <iostream>
using namespace std;

int T, N, M;
int dp[30][30];

int main(){
    cin >> T;
    
    for(int i=1; i<=29; i++){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    
    for(int i=2; i<=29; i++){
        for(int j=1; j<i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    while(T--){
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }

    return 0;
}