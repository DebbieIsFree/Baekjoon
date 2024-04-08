#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
int ans = 0;

// 틀린 이유 : 자료형을 long long으로 안 하고 int로 해서

int main(){
    cin >> N >> M;
    
    vector<long long> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    //  
    long long left = 0;
    long long right = v[N-1];
    
    while(left <= right){
        long long mid = (left + right) / 2;
        
        long long tmp = 0;
        
        for(int i=0; i<N; i++){
            if(v[i] >= mid){
                tmp += (v[i] - mid);
            }
        }
        
        if(tmp > M){
            left = mid + 1;
            ans = mid;
        }
        else if(tmp < M){
            right = mid - 1;
        }
        else {
            ans = mid;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
