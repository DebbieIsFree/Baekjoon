#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001];

int main(){
    cin >> N >> K;
    
    queue<pair<int,int>> q;
    q.push({N, 0});
    visited[N] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == K){
            cout << cnt;
            break;
        }
        
        if(cur*2 <= 100000 && !visited[cur*2]){
            visited[cur*2] = true;
            q.push({cur*2, cnt});
        }
        if(cur-1 >= 0 && !visited[cur-1]){
            visited[cur-1] = true;
            q.push({cur-1, cnt+1});
        }
        if(cur+1 <= 100000 && !visited[cur+1]){
            visited[cur+1] = true;
            q.push({cur+1, cnt+1});
        }
    }

    return 0;
}