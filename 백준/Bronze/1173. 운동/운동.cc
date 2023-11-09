#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    
    int tm = 0;
    int work_out = 0;
    int heartbeat = m;
    
    if(m + T > M){
        cout << "-1";
        return 0;
    }
    
    while(work_out < N){
        tm++;
        
        if(heartbeat + T <= M){
            heartbeat += T;  
            work_out++;
        }
        else{
            heartbeat = max(m, heartbeat - R);
        }
    }
    
    cout << tm;
    
    return 0;
}



