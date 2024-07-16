#include <iostream>
#include <queue>
#include <set>
#include <string>
#define INF 1000000000
using namespace std;


int main(){
    long long A, B;
    cin >> A >> B;
    
    queue<pair<long long, int>> q;
    set<long long> s;
    
    q.push({A, 1});
    s.insert(A);
    
    int answer = -1;
    
    while(!q.empty()){
        long long cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == B){
            answer = cnt;
            break;
        }
        
        if(s.find(cur *2) == s.end() && cur*2 <= INF){
            q.push({cur*2, cnt+1});
            s.insert(cur * 2);
        }
        
        string str = "";
        str += to_string(cur);
        str += "1";
        long long n = stoll(str);
        
        if(s.find(n) == s.end() && n <= INF){
            q.push({n, cnt+1});
            s.insert(n);
        }
    }
    
    if(answer == -1){
        cout << "-1";
    }else{
        cout << answer;
    }

    return 0;
}