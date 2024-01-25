#include <iostream>
using namespace std;


long long v[1000001];
long long dp[1000001];


int main(){
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    
    
    int n;  cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    
    int cnt = 0;
    
    dp[0] = - 1000000001;
    
    for(int i=1; i<=n; i++){
        if(dp[cnt] < v[i]){
            ++cnt;
            dp[cnt] = v[i];
        }
        
        else{
            int left = 1;
            int right = cnt;
            int mid;
            
            bool flag = false;
            
            // nlogn
            while(left <= right){
                mid = (left + right) / 2;
                    
                if(dp[mid] == v[i]){
                    flag = true;
                    break;
                }
                else if(dp[mid] < v[i]){
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(!flag)
                dp[left] = v[i];
        }
    }
    
    // cout << endl;
    // for(int i=1; i<=cnt; i++){
    //     cout << dp[i] << " ";
    // }
    
    cout << cnt;
    
    return 0;
}
