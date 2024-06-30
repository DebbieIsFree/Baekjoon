#include <iostream>
#include <queue>
using namespace std;

int N, M;
char arr[600][600];
bool visited[600][600];
int cnt = 0;
int sr, sc;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(){
    queue<pair<int,int>> q;
    
    visited[sr][sc] = true;
    q.push({sr, sc});
    
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || arr[nr][nc] == 'X')
                continue;
                
            if(arr[nr][nc] == 'P')
                cnt++;
                
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j];
            if(str[j] == 'I'){
                sr = i;
                sc = j;
            }
        }
    }
    
    bfs();
    
    if(cnt == 0)
        cout << "TT";
    else 
        cout << cnt;

    return 0;
}