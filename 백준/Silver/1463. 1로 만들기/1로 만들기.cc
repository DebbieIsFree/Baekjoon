#include <iostream>
#include <queue>
using namespace std;

int N;
bool visited[1000001];

int main(){
    cin >> N;
    
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;
    
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == 1){
            cout << cnt;
            break;
        }
        
        if(cur % 3 == 0 && !visited[cur/3]){
            q.push({cur / 3, cnt+1});
            visited[cur/3] = true;
        }
        if(cur % 2 == 0 && !visited[cur/2]){
            q.push({cur / 2, cnt+1});
            visited[cur/2] = true;
        }
        if(cur -1 >= 1 && !visited[cur-1]){
            q.push({cur-1, cnt+1});
            visited[cur-1] = true;
        }
    }
        

    return 0;
}