#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;  cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    while(N--){
        cin >> n;
        
        if(n == 0){
            if(pq.empty()){
                cout << "0\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }else{
            pq.push(n);
        }
    }

    return 0;
}