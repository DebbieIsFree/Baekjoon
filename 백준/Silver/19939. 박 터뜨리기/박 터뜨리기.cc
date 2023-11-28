#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(K+1);
    
    int sum = 0;
    
    v[0] = 0;
    
    for(int i=1; i<=K; i++){
        v[i] = v[i-1] + 1;
        sum += v[i];
    }
    
    N -= sum;
    
    if(N <0){
        cout << "-1";
        return 0;
    }
    
    int res = N % K;
    
    while(res >= K){
        for(int i=1; i<=K; i++){
            v[i] += 1;
        }
        res = res - K;
    }
    
    
    if(res >= 1){
        for(int i=0; i<res; i++){
            v[K-i] += 1;
        }
    }
   
   
    for(int i=1; i<=K; i++){
        for(int j=i+1; j<=K; j++){
            if(v[i] == v[j]){
                cout << "-1";
                return 0;
            }
        }
    }
    
    cout << v[K] - v[1];

    return 0;
}
