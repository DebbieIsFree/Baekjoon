#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v(N+1);
    
    for(int i=1; i<=N; i++){
        v[i] = i;
    }
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        int tmp = v[a];
        v[a] = v[b];
        v[b] = tmp;
    }
    
    for(int i=1; i<=N; i++){
        cout << v[i] << " ";
    }

    return 0;
}
