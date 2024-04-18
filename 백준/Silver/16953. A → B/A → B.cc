#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){

    int A, B;
    cin >> A >> B;
    
    // num, breadth
    queue<pair<long long, int>> q;
    
    q.push({A, 1});
    
    while(!q.empty()){
        long long num = q.front().first;
        int breadth = q.front().second;
        q.pop();
        
        if(num == B){
            cout << breadth;
            return 0;
        }
        
        // string str = to_string(num);
        // str += "1";
        
        long long tmp = num * 10 +1;
        
        if(num*2 <= B)
            q.push({num*2, breadth+1});
        if(tmp <= B)
            q.push({tmp, breadth+1});
    }
    
    cout << "-1";

    return 0;
}
