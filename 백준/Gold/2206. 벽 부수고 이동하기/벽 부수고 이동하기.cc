#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int ans = 987654321;
int arr[1000][1000];
int visited[1000][1000][2];         // 0 : not broken,   1 : broken

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct Node{
    bool flag;      // is broken?
    int row, col;
};

void bfs(){
    queue<Node> q;
    q.push({false, 0, 0});
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    
    while(!q.empty()){
        int cr = q.front().row;
        int cc = q.front().col;
        bool flag = q.front().flag;
        q.pop();
        
        if(cr == N-1 && cc == M-1){
            if(visited[cr][cc][0] > 0)
                ans = min(ans, visited[cr][cc][0]);
            if(visited[cr][cc][1] > 0)
                ans = min(ans, visited[cr][cc][1]);
        }
        
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            
            if(!flag && arr[nr][nc] == 1 && !visited[nr][nc][1]){
                visited[nr][nc][1] = visited[cr][cc][0] + 1;
                q.push({true, nr, nc});
            }
            else if(flag && arr[nr][nc] == 0 && !visited[nr][nc][1]){
                visited[nr][nc][1] = visited[cr][cc][1] + 1;
                q.push({flag, nr, nc});   
            }
            else if(!flag && arr[nr][nc] == 0 && !visited[nr][nc][0]){
                visited[nr][nc][0] = visited[cr][cc][0] + 1;
                q.push({flag, nr, nc});   
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j] - '0';
        }
    }
    
    bfs();
    
    if(ans == 987654321)
        cout << "-1";
    else
        cout << ans;
    
    return 0;
}