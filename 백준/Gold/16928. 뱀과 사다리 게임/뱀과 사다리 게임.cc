#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;   // ladder, snake
int ladder[101];
int snake[101];
bool visited[101];

int main(){
    cin >> N >> M;
    
    fill_n(ladder, 101, -1);
    fill_n(snake, 101, -1);
    
    // 사다리 입력
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        ladder[x] = y;
    }
    
    // 뱀 입력
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        snake[u] = v;
    }
    
    queue<pair<int, int>> q;    // {curLoc, cnt}
    q.push({1, 0});
    visited[1] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == 100){
            cout << cnt;
            break;
        }
        
        // 주사위를 던지면 어떤 숫자가 나올 지 모름
        for(int i=1; i<=6; i++){
            int next = cur + i;
            
            if(next < 1 || next > 100)
                continue;
            
            if(ladder[next] != -1){
                next = ladder[next];
            }
            else if(snake[next] != -1){
                next = snake[next];
            }
            
            if(visited[next])
                continue;
            
            visited[next] = true;
            q.push({next, cnt+1});
        }
    }
    
    return 0;
}