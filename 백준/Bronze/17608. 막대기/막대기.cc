#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N; cin >> N;
    
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    int cnt = 1;
    int m = v[N-1];
    
    for(int i=N-2; i>=0; i--){
        if(m < v[i]){
            cnt++;
            m = v[i];
        }
    }
    
    cout << cnt;

    return 0;
}
