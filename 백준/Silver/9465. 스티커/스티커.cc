#include <iostream>
#include <algorithm>
using namespace std;

int arr[3][100001];
int dp[3][100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;  cin >> T;
    
    while(T--){
        int n;  cin >> n;
        
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin >> arr[i][j];
            }
        }
        
        dp[1][1] = arr[1][1];
        dp[2][1] = arr[2][1];
        
        // dp[1][2] = arr[2][1]+ arr[1][2];
        // dp[2][2] = arr[1][1] + arr[2][2];
        
        for(int i=2; i<=n; i++){
            dp[1][i] = max(dp[2][i-1], dp[2][i-2]) + arr[1][i];
            dp[2][i] = max(dp[1][i-1], dp[1][i-2]) + arr[2][i];
        }
        
        cout << max(dp[1][n], dp[2][n]) << "\n";
    }

    return 0;
}