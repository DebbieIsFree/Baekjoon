#include <iostream>
#include <algorithm>
using namespace std;

int dp[201];
int arr[201];

int main(){
    
    int N;  cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }

    int max_val = 0;
    
    for(int i=1; i<=N; i++){
        dp[i] = 1;
        
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i] ){
                dp[i] = max(dp[i], dp[j] + 1);
                max_val = max(dp[i], max_val);
            }
        }
    }

    
    cout << N - max_val;

    return 0;
}
