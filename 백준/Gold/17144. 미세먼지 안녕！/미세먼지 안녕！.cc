#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R, C, T;
vector<pair<int,int>> v;     // 공기 청정기 위치 {row, col}
int map[51][51];
queue<pair<int,int>> q;     // 먼지 위치 저장 {row, col}
int tmp[51][51];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 반시계 방향 회전
int r2dr[] = {0, -1, 0, 1};
int r2dc[] = {1, 0, -1, 0};

// 시계 방향 회전
int r1dr[] = {0, 1, 0, -1};
int r1dc[] = {1, 0, -1, 0};

int main(){
    cin >> R >> C >> T;
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> map[i][j];
            
            if(map[i][j] == -1){
                v.push_back({i, j});
                map[i][j] = 0;
            }
            else if(map[i][j] > 0){
                q.push({i, j});
            }
        }
    }
    
    sort(v.begin(), v.end());       // 공기청정기 row 기준 오름차순 정렬 ([0]--> 위, [1] --> 아래)
    
    while(T--){
        // 매 초마다 임시 저장소 초기화
        fill(&tmp[0][0], &tmp[0][0] + 51*51, 0);
        
        // step 1) 미세먼지 확산
        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            int amount = map[cr][cc];
            
            int cnt = 0;
            
            for(int i=0; i<4; i++){
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                
                if(nr <= 0 || nr > R || nc <= 0 || nc > C)
                    continue;
                    
                if( (nr == v[0].first && nc == 1) || (nr == v[1].first && nc == 1) )
                    continue;
                
                cnt++;
                tmp[nr][nc] += amount / 5;
            }
            tmp[cr][cc] += amount - (amount/5*cnt);
            if(tmp[cr][cc] < 0)
                tmp[cr][cc] = 0;
        }
        
        // 미세먼지 확산된 결과 반영
        copy(&tmp[0][0], &tmp[0][0] + 51*51, &map[0][0]);
        

        // step 2) 공기청정기 가동
        // 빈 배열
        copy(&tmp[0][0], &tmp[0][0] + 51*51, &map[0][0]);
        
        // 위쪽 >> 반시계
        int dir = 0;
        int r = v[0].first;
        int c = 1;
        
        while(true){
            if((r==1 && c==1) || (r==v[0].first && c==C) || (r==1 && c==C)){
                dir = (dir+1)%4;
            }
            int nr = r + r2dr[dir];
            int nc = c + r2dc[dir];
            
            if(nr == v[0].first && nc == 1){
                map[nr][nc] = 0;
                break;
            }
            
            if(nr == v[0].first && nc == 2){
                map[nr][nc] = 0;
            }
            else{
                map[nr][nc] = tmp[r][c];    
            }
            r = nr;
            c = nc;
        }
        
        // 아래쪽 >> 시계 
        dir = 0;
        r = v[1].first;
        c = 1;
        
        while(true){
            if((r==v[1].first && c==C) || (r==R && c==C) || (r==R && c==1)){
                dir = (dir+1)%4;
            }
            int nr = r + r1dr[dir];
            int nc = c + r1dc[dir];
            
            if(nr == v[1].first && nc == 1){
                map[nr][nc] = 0;
                break;
            }
            
            if(nr == v[1].first && nc == 2){
                map[nr][nc] = 0;
            }
            else{
                map[nr][nc] = tmp[r][c];    
            }
            r = nr;
            c = nc;
        }
        
        // 매 초마다 새로 바뀐 미세먼지 위치 -->  queue에 삽입
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(map[i][j] > 0){
                    q.push({i, j});
                }
            }
        }
    }
    
    int sum = 0;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            sum += map[i][j];
        }
    }
    
    cout << sum;

    return 0;
}