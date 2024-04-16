#include <iostream>
using namespace std;

int arr[17][17];
int dp[17][17][3];      // [row][col] →, ↘, ↓

int main(){
    int N;  cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[1][2][0] = 1;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==1 && (j==1 || j==2))
                continue;
            
            if(arr[i][j] == 1)
                continue;
            
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][1];
            dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2];
            
            if(arr[i-1][j] != 1 && arr[i][j-1] != 1){
                dp[i][j][1] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }
    
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];  

    return 0;
}


