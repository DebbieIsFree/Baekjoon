#include <iostream>
#include <queue>
using namespace std;


int main(){
    
    int N;  cin >> N;
    
    priority_queue<int> pq;
    
    while(N--){
        int a;  cin >> a;
        
        if(a == 0){
            if(pq.empty()){
                cout << "-1\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            while(a--){
                int n;  cin >> n;
                pq.push(n);
            }
        }
    }
    
    return 0;
}
