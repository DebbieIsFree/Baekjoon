#include <iostream>
#include <vector>
using namespace std;

struct Node{
  int row, col;  
};

int map[100][100];
int N;  // 한 변 길이
bool wh[5];     // 6~10

// 상, 우, 하, 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int changeDir[6][4] = {
    {0,0,0,0}, // 0 : dummy
    {2,3,1,0}, // 1
    {1,3,0,2}, // 2
    {3,2,0,1}, // 3
    {2,0,3,1}, // 4     // 틀린 이유 {2,2,3,1}이 아니라, {2,0,3,1}이다!
    {2,3,0,1}  // 5
};

int ans = -1e9;

vector<vector<Node>> v(5);  // 6 ~ 10


// 무한루프 신경 안 써도 됨 <--- 출발지로 다시 돌아오면 종료되기 때문.
// ex) 5 0 0 0 0(출발)
//       <- <- <-
//     -> -> -> 출발지로 다시 돌아옴(종료)

// 점수는 벽이나 블록에 부딪힌 횟수가 된다.
void func(int row, int col, int d){
    int nr = row;
    int nc = col;
    int dir = d;
    int sum = 0;
    
    while(1){
        nr += dr[dir];
        nc += dc[dir];
        
        // 블랙홀 --> 종료
        // 시작 위치로 돌아옴 --> 종료
        if((nr == row && nc == col) || (map[nr][nc] == -1)){  
            ans = max(ans, sum);
            break;
        }
        else if(nr < 0 || nr == N || nc < 0 || nc == N){ // 벽 --> 방향 반대로
            sum++;
            dir = changeDir[5][dir];
        }
        else if(1 <= map[nr][nc] && map[nr][nc] <= 5){ // 블록 --> 방향 변경 & count++
            sum++;
            int n = map[nr][nc];
            dir = changeDir[n][dir];
        }else if(6 <= map[nr][nc] && map[nr][nc] <= 10){ // 웜홀 --> 다른 웜홀로 이동(방향은 그대로)
            int idx = map[nr][nc] - 6;
            
            // if(wh[idx]){
            //     ans = max(ans, sum);
            //     break;
            // }
            
            if(v[idx][0].row == nr && v[idx][0].col == nc){
                nr = v[idx][1].row;
                nc = v[idx][1].col;
            }else{
                nr = v[idx][0].row;
                nc = v[idx][0].col;
            }
            // wh[idx] = true;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        
        // v.clear();
        for (int i = 0; i < 5; i++) {
            v[i].clear();
            wh[i] = false;
        }
        
        // 입력 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                
                if(6 <= map[i][j] && map[i][j] <= 10){  // 웜홀
                    v[map[i][j] - 6].push_back({i, j});
                }
            }
        }
        
        ans = -1e9;
        
        // 풀이
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == 0){
                    for(int d=0; d<4; d++){
                        func(i, j, d);
                    }
                }
            }
        }
        
        cout << "#" << tc << " " << ans << "\n";
    }
    
    return 0;
}


