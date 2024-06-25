#include <iostream>
#include <queue>
using namespace std;

int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    priority_queue<int> pq;
    
    while(N--){
        int n;  cin >> n;
        
        if(n > 0){
            pq.push(n);
        }else{
            if(pq.empty()){
                cout << "0\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}