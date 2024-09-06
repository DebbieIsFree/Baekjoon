#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[16][16];
int ans = 0;

int main(){
    cin >> N;
    
    for(int i=1; i<=N; i++){
        int t, p;
        cin >> t >> p;
        
        int start = i;
        int end = start + t - 1;
        
        if(end > N)
            continue;
        
        for(int j=1; j<start; j++){
            for(int k=1; k<start; k++){
                dp[start][end] = max(dp[start][end], dp[j][k]);
            }
        }
        
        dp[start][end] += p;
        
        ans = max(dp[start][end], ans);
    }
    
    cout << ans;

    return 0;
}