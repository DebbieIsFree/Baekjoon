#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N+1, 0);
    
    for(int i=0; i<M; i++){
        int s, e, k;
        cin >> s >> e >> k;
        
        for(int h=s; h<=e; h++){
            v[h] = k;
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << v[i] << " ";
    }

    return 0;
}
