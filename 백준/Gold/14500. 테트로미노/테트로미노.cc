#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[500][500];
int ans = 0;
int r, c;
int index;

vector<vector<int>> dr = {
    {0, 0, 0, 0},
    {0, 0, 1, 1},
    {0, 1, 2, 2},
    {0, 1, 1, 2},
    {0, 0, 0, 1},
    {0, 1, 2, 3},   // 
    {0, 0, 0, 1},   
    {0, 0, 1, 2},   
    {0, 0, 0, -1},  
    {0, 0, 1, 1},   
    {0, 1, 2, 1},   
    {0, 0, 0, -1},  
    {0, 1, 2, 1},
    {0, 0, 0, 1},   //  
    {0, 0, 1, 2},
    {0, 0, 1, 1},
    {0, 1, 1, 2},
    {0, 1, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 1, 2},   //
    {0, 1, 2, 2}
};

vector<vector<int>> dc = {
    {0, 1, 2, 3},
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 1, 1},
    {0, 1, 2, 1},
    {0, 0, 0, 0},   // 
    {0, 1, 2, 0},   
    {0, 1, 1, 1},   
    {0, 1, 2, 2},   
    {0, 1, -1, 0},  
    {0, 0, 0, -1},  
    {0, 1, 2, 1},   
    {0, 0, 0, 1},   
    {0, 1, 2, 2}, //    
    {0, 1, 0, 0},
    {0, 1, 1, 2},
    {0, 0, -1, -1},
    {0, 0, 1, 2},
    {0, 1, 2, 2},  
    {0, 1, 0, 0},
    {0, 0, 0, -1}
};

int coloring(int row, int col, int idx){
    int sum = 0;
    
    for(int i=0; i<4; i++){
        int nr = row + dr[idx][i];
        int nc = col + dc[idx][i];
        
        sum += map[nr][nc];
    }
    return sum;
}

void func(int row, int col){
    for(int i=0; i<21; i++){
        int cnt = 0;
        
        for(int d=0; d<4; d++){
            int nr = row + dr[i][d];
            int nc = col + dc[i][d];
            
            if(nr < 0 || nr >= N || nc < 0 || nc >= M){
                break;    
            }
            cnt++;
        }
        
        if(cnt == 4){
            int tmp = coloring(row, col, i);
            ans = max(ans, tmp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            func(i, j);
        }
    }
    
    cout << ans;
    
    return 0;
}
