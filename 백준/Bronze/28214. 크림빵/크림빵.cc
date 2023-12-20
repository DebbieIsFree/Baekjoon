#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N, K, P;
    cin >> N >> K >> P;
    
    vector<int> v(N*K);
    
    for(int i=0; i<N*K; i++){
        cin >> v[i];
    }
    
    int ans = 0;
    
    for(int i=0; i<N*K; i+=K){
        int cnt = 0;
        for(int j=i; j<i+K; j++){
            if(!v[j])
                cnt++;
        }
        if(cnt < P)
            ans++;
    }
    
    cout << ans;
    
    return 0;
}
