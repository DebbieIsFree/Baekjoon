#include <iostream>
#include <algorithm>
using namespace std;

int R, C, T;

int map[50][50];
int temp[50][50];

// 공기 청정기 위치
int col, urow = -1, drow;

// 우 하 좌 상 (아래쪽 공기청정기 방향 )
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

// 우 상 좌 하  (위쪽 공기 청정기 방향)
int dr2[] = {0, -1, 0, 1};
int dc2[] = {1, 0, -1, 0};

int main(){
    cin >> R >> C >> T;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
            
            if(map[i][j] == -1){
                if(urow == -1){
                    urow = i;
                    col = j;
                }else{
                    drow = i;
                }
            }
        }
    }

    while(T--){
        
        // 매초마다 증감 관리 배열은 0으로 초기화 
        fill(&temp[0][0], &temp[49][50], 0);
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                // 공기 청정기에서는 먼지가 퍼질 수 없다.
                if((i == urow || i == drow) && j == col)
                    continue;
                
                int ad = map[i][j] / 5;
                int cnt = 0;    // 사방 중 퍼진 개수
                
                // 사방 탐색
                for(int d=0; d<4; d++){
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    
                    // 범위 체크  + 공기 청정기로는 먼지가 들어갈 수 없다.
                    if(nr < 0 || nr >= R || nc < 0 || nc >= C || ((nr == urow || nr == drow) && nc == col))
                        continue;
                        
                    temp[nr][nc] += ad;
                    cnt++;
                }
                temp[i][j] -= (ad * cnt);
            }
        }
        
        // 원본 배열에 증감 변동 사항 반영
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if((i == urow || i == drow) && j == col)
                    continue;
                
                map[i][j] = map[i][j] + temp[i][j];
                
                if(map[i][j] < 0) 
                    map[i][j] = 0;
            }
        }
     
        
        // 위, 아래 각각 공기 청정기 돌리기
        int r, c, dir, prev;
        
        // 위쪽
        r = urow;
        c = 2;
        dir = 0;
        prev = map[urow][1];
        
        // r != urow && c != 0 하니까 안됨..
        while(!(r == urow && c == 0)){
            int tmp = map[r][c];
            map[r][c] = prev;
            prev = tmp;
            
            // while문 안에서 if 조건문 위치 중요..
            // 순환 고리의 3개의 꼭짓점에서 다 처리하고, 그 다음에 방향 바꾸기
            if((r == urow && c == C-1) || (r == 0 && c == C-1) || (r == 0 && c == 0))
                dir = (dir + 1) % 4;
            
            r = r + dr2[dir];
            c = c + dc2[dir];
        }
        map[urow][0] = 0;
        map[urow][1] = 0;
        
        // 아래쪽
        r = drow;
        c = 2;
        dir = 0;
        prev = map[drow][1];
        
        // r != drow && c != 0 쓰니까 안됨..
        while(!(r == drow && c == 0)){
            int tmp = map[r][c];
            map[r][c] = prev;
            prev = tmp;
            
            // while문 안에서 if 조건문 위치 중요..
            // 순환 고리의 3개의 꼭짓점에서 다 처리하고, 그 다음에 방향 바꾸기
            if((r == drow && c == C-1) || (r==R-1 && c == C-1) || (r == R-1 && c == 0))
                dir = (dir + 1) % 4;
            
            r = r + dr[dir];
            c = c + dc[dir];
        }
        map[drow][0] = 0;   // 공기 청정기로 들어가면 소멸
        map[drow][1] = 0;   // 공기 청정기에서 나오는건 0   
    }

    int sum = 0;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if((i == urow || i == drow) && j == col)
                continue;
            sum += map[i][j];    
        }
    }

    cout << sum;

    return 0;
}

