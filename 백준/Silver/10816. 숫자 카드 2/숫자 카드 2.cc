#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    int a;
    
    map<int, int> m;
    
    while(N--){
        cin >> a;
        m[a] += 1;
    }
    
    cin >> M;
    
    while(M--){
        cin >> a;
        cout << m[a] << " ";
    }
   
    return 0;
}