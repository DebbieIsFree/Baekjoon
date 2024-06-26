#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;      // {절댓값, 원래값}

int main(){
    int N;  cin >> N;
    
    while(N--){
        int n;  cin >> n;
        
        if(n != 0){
            pq.push({abs(n), n});
        }else{
            if(pq.empty()){
                cout << "0\n";
            }else{
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}