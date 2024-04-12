#include <iostream>
#include <algorithm>
using namespace std;

// 메모리 초과
// int arr[100001][3]       // 입력값
// int max_dp[100001][3]    // 최대값 dp
// int min_dp[100001][3]    // 최소값 dp 

// --> 슬라이딩 윈도우

int min_dp[3];
int max_dp[3];

int main(){
    int N;  cin >> N;
    
    // 입력 받으면서 바로 계산
    
    for(int i=1; i<=N; i++){
        int tmp0 = max_dp[0];
        int tmp1 = max_dp[1];
        int tmp2 = max_dp[2];
        
        int t0 = min_dp[0];
        int t1 = min_dp[1];
        int t2 = min_dp[2];
        
        for(int j=0; j<3; j++){
            int input;
            cin >> input;

            // max_dp
            if(j == 0)
                max_dp[0] = max(tmp0, tmp1) + input;
            else if(j == 1)
                max_dp[1] = max(tmp0, max(tmp1, tmp2)) + input;
            else if(j == 2)
                max_dp[2] = max(tmp1, tmp2) + input;
            
            
            // min_dp
            if(j== 0)
                min_dp[0] = min(t0, t1) + input;
            else if(j == 1)
                min_dp[1] = min(t0, min(t1, t2)) + input;
            else if(j == 2)
                min_dp[2] = min(t1, t2) + input;
        }
    }
    
    int min_ans = min(min_dp[0], min(min_dp[1], min_dp[2]));
    int max_ans = max(max_dp[0], max(max_dp[1], max_dp[2]));
    
    cout << max_ans << " " << min_ans;

    return 0;
}

