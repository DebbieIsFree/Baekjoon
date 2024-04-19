#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int arr[125][125];
int dist[125][125];
// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

const int INF = INT_MAX;

// struct Node{
//   int row, col, cost;  
// };

void dijkstra(){
    // cost, {row, col}
    priority_queue<pair<int, pair<int, int>>> pq;
    
    // 시작 지점 (0,0)
    pq.push({arr[0][0], {0,0}});
    dist[0][0] = arr[0][0];
    
    while(!pq.empty()){
        pair<int, pair<int, int>> node = pq.top();
        pq.pop();
        
        int cr = node.second.first;
        int cc = node.second.second;
        int cst = -node.first;
        
        // if(cr == N-1 && cc == N-1){
        //     break;
        // }
        
        // 상하좌우
        for(int i=0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
                
            if(dist[nr][nc] < cst)
                continue;
            
            if(dist[nr][nc] > dist[cr][cc] + arr[nr][nc]){
                dist[nr][nc] = dist[cr][cc] + arr[nr][nc];
                pq.push({-dist[nr][nc], {nr, nc}});
            }   
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 0;
    while(1){
        tc++;
        cin >> N;
        
        if(N == 0)
            break;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }
        
        fill(&dist[0][0], &dist[0][0] + 125*125, INF);
        
        
        // for(int i=0; i<N; i++){
        //     dist[i][i] = 0;
        // }
        
        dijkstra();
        
        cout << "Problem " << tc << ": " << dist[N-1][N-1] << "\n";
    }
    
    return 0;
}

