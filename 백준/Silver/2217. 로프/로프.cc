#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    vector<int> v(N);
    
    int sum = 0;
    
    for(int i=0; i<N; i++){
        cin >> v[i];
        sum += v[i];
    }
    
    sort(v.begin(), v.end());
    
    sum = sum / N;
    
    int ans = 0;
    
    for(int i=0; i<N; i++){
        if(ans < v[i] * (N - i)){
            ans = v[i] * (N - i);
        }
    }

    cout << ans;

    return 0;
}
