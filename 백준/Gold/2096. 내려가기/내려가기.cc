#include <iostream>
#include <algorithm>
using namespace std;

int min_dp[3];
int max_dp[3];

int main(){
    int N, input1, input2, input3, tmp1, tmp2;  cin >> N;
    
    for(int i=1; i<=N; i++){
            cin >> input1 >> input2 >> input3;
            tmp1 = max_dp[0];
            tmp2 = max_dp[2];
            max_dp[0] = max(max_dp[0], max_dp[1]) + input1;
            max_dp[2] = max(max_dp[1], max_dp[2]) + input3;
            max_dp[1] = max(max_dp[1], max(tmp1, tmp2)) + input2;
            
            tmp1 = min_dp[0];
            tmp2 = min_dp[2];
            min_dp[0] = min(min_dp[0], min_dp[1]) + input1;
            min_dp[2] = min(min_dp[1], min_dp[2]) + input3;
            min_dp[1] = min(min_dp[1], min(tmp1, tmp2)) + input2;
    }
    
    
    int min_ans = min(min_dp[0], min(min_dp[1], min_dp[2]));
    int max_ans = max(max_dp[0], max(max_dp[1], max_dp[2]));
    
    cout << max_ans << " " << min_ans;

    return 0;
}