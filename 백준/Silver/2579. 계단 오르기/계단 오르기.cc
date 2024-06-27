#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301][3];

int main(){
    int N;  cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    
    dp[1][1] = arr[1];

    for(int i=2; i<=N; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }
    
    cout << max(dp[N][1], dp[N][2]);

    return 0;
}