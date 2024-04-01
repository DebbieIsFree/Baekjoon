#include <iostream>
#include <queue>

using namespace std;

int M, N, H;

int map[100][100][100];
int visited[100][100][100];

// 6방향
int dr[] = {-1, 0, 1, 0, 0, 0};
int dc[] = {0, 1, 0, -1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

int cnt = 0;    // 익지 않은 토마토 개수
int K = 0;      // bfs 돌면서,  안 익은 토마토 --> 익은 토마토 되는 개수 세기
int maxDist = 0;

queue<pair<int, pair<int, int>>> q;


void bfs(){
    while(!q.empty()){
        pair<int, pair<int, int>> node = q.front();
        q.pop();
        
        int ch = node.first;
        int cr = node.second.first;
        int cc = node.second.second;
        
        for(int d=0; d<6; d++){
            int nh = ch + dh[d];
            int nr = cr + dr[d];
            int nc = cc + dc[d];
            
            // 범위 체크
            if(nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            // 이미 방문했던 곳, 토마토가 없는 곳으로는 이동 불가
            if(visited[nh][nr][nc] != 0 || map[nh][nr][nc] != 0)
                continue;
        
            visited[nh][nr][nc] = visited[ch][cr][cc] + 1;
            q.push({nh, {nr, nc}});
            
            K++;
            if(maxDist < visited[nh][nr][nc])
                maxDist = visited[nh][nr][nc];
        }
    }
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> M >> N >> H;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin >> map[i][j][k];
                if (map[i][j][k] == 0){
                    cnt++;
                }
                else if(map[i][j][k] == 1){
                    q.push({i, {j, k}});
                }
            }
        }
    }
    
    if(cnt == 0){
        cout << "0";
        return 0;
    }
    
    bfs();

    if(K != cnt){
        cout << "-1";
    }else{
        cout << maxDist;
    }

    

    return 0;
}

