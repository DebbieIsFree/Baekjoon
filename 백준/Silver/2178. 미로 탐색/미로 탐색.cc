#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[100][100];
bool visited[100][100];

struct Node{
  int row, col, cnt;  
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(){
    queue<Node> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while(!q.empty()){
        int cr = q.front().row;
        int cc = q.front().col;
        int cnt = q.front().cnt;
        q.pop();
        
        if(cr == N-1 && cc == M-1){
            cout << cnt;
            break;
        }
        
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || arr[nr][nc] == 0)
                continue;
            
            visited[nr][nc] = true;
            q.push({nr, nc, cnt+1});
        }
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j] - '0';
        }
    }
    
    bfs();
    
    return 0;
}