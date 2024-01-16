#include <iostream>

using namespace std;

int main(){
    
    
    int T;  cin >> T;
    
    while(T--){
        int N, M;
        cin >> N >> M;
        
        long long res = 1;
        int d = 1;
        
        for(int i=M; i>=M-N+1; i--){
            res *= i;   
            res /= d;
            d++;
        }
        
        cout << res << "\n";
    }
    
    return 0;
}
