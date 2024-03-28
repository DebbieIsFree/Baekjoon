#include <iostream>
using namespace std;

int N, M;

// U, D, L, R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int map[1000][1000];
int visited[1000][1000];
int ans = 0;  // safe zone 개수

int dfs(int row, int col){
    visited[row][col] = 1;
    
    int dir = map[row][col];
    int nr = row + dr[dir];
    int nc = col + dc[dir];
    
    // 다음으로 이동하려는 곳이 한 번도 방문한 적 없다면
    // 계속 이동
    if(visited[nr][nc] == 0){
        int r = dfs(nr, nc);    
        if(r == 2)
            return visited[row][col] = 2;
    }
    // 이미 방문한 곳이라면 --> 사이클 발생 --> safe zone 개수 증가
    else if(visited[nr][nc] == 1){
        ans++;    
        visited[nr][nc] = 2;
    }
    
    // 함수 호출 스택 리턴되면서 방문한 곳은 다 2로 바꿈
    return visited[row][col] = 2;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char d; cin >> d; 
            if(d == 'U')
                map[i][j] = 0;
            else if(d == 'D')
                map[i][j] = 1;
            else if(d == 'L')
                map[i][j] = 2;
            else 
                map[i][j] = 3;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j])
                dfs(i, j);
        }
    }
    
    cout << ans;
    
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}


