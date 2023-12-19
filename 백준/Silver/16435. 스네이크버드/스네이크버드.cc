#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int N, L;
    cin >> N >> L;
    
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        if(v[i] <= L){
            L++;
        }
    }

    cout << L;
    
    return 0;
}
