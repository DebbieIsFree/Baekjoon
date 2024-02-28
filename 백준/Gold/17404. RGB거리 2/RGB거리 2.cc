#include <iostream>
#include <algorithm>
using namespace std;

int input[1001][3];
int dp[1001][3][3]; // [N번째 집] [N번째 집 색깔 0~2][맨 처음 집 색깔 0~2]

int main(){
    int N; cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }
    
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j) 
                dp[1][i][j] = input[1][i];
            else
                dp[1][i][j] = 1e9;
        }
    }
    
    dp[1][0][0] = input[1][0];
    dp[1][1][1] = input[1][1];
    dp[1][2][2] = input[1][2];
    
    for(int i=2; i<=N; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(i==N && j==k){
                    dp[i][j][k] = 1e9;
                    continue;
                }
                dp[i][j][k] = min(dp[i-1][(j+1) % 3][k],  dp[i-1][(j+2) % 3][k]) + input[i][j];
            }
        }
    }
    
    int ans = 1e9;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j)
                continue;
            if(dp[N][i][j] < ans)
                ans = dp[N][i][j];
        }
    }
    
    cout << ans;
    
    
    return 0;
}
