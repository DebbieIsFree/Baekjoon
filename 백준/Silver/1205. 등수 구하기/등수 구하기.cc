#include <iostream>
#include <queue>
using namespace std;

int main(){
    long long N, S, P;
    cin >> N >> S >> P;
    
    priority_queue<int> pq;
    
    for(int i=0; i<N; i++){
        int p;  cin >> p;
        pq.push(p);
    }
    
    int cnt = 1;
    int ans = 1;
    
    while(!pq.empty()){
        if(pq.top() > S){
            pq.pop();
            ans++;
            cnt++;
        }else if(pq.top() == S){
            cnt++;
            pq.pop();
        }
        else if(pq.top() < S){
            break;
        }
    }
    
    if(cnt <= P){
        cout << ans;
    }else{
        cout << "-1";
    }

    return 0;
}