#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
int ans = 1e9;      // 최소값 찾기 --> 최대값으로 초기화
int paper[6];

// 전역 변수 row, col을 사용하면
// 재귀 호출할 때마다 변하는 값을 전달하지 못하므로
// dfs() 함수의 매개변수에 좌표값을 전달한다.

void dfs(int row, int col, int cnt){
    
    // 재귀 호출된 시점에서, 가장 위 & 왼쪽에 있는 map[][] == 1인 곳 찾기
    int nr = row;
    int nc = col;
    bool flag = false;
    
    while(nr < 10){     
        if(map[nr][nc] == 1){
            row = nr;
            col = nc;
            flag = true;
            break;
        }
        
        nc++;
        
        if(nc == 10){
            nr++;
            nc = 0;
        }
    }
    
    // 기저 조건 - (더 이상 map[][] == 1인 곳이 없을 때) 
    if(!flag){
        // 사용한 색종이 개수 비교
        ans = min(ans, cnt);
        return;
    }
    
    // 색종이 크기 1부터 5까지 다 갖다대보기
    // 성공해도 실패해도 다른 사이즈 시도
    for(int i=1; i<=5; i++){    
        
        // 색종이 5개 다 사용했으면 다른 사이즈 시도
        if(paper[i] == 5)
            continue;
        
        // 색종이가 종이 크기를 벗어나면 안됨
        // !!! 범위 계산 !!!!
        // ex) row == 5 일 때, size가 5인 색종이를 붙이면
        //  row = 5, 6, 7, 8, 9에 붙여짐, row(5) + i(5) == 10이므로 
        // nr + (i-1) >= 10 or nr + i > 10으로 고쳐야 함
        if(nr + i > 10 || nc + i > 10)
            continue;
        
        // 색종이 붙이려는 곳은 모두 map[][] 값이 1이어야 함 
        bool flag = true;
        
        for(int r=nr; r<nr+i; r++){
            for(int c=nc; c<nc+i; c++){
                if(map[r][c] == 0){
                    flag = false;
                    break;
                }
            }
        }
        
        if(!flag)
            continue;
            
        // 다음 좌표가 1인 곳에 색종이 붙이러 가기 
        
        // 1) 현재 색종이 붙이고 (1 --> 0)
        for(int r=nr; r<nr+i; r++){
            for(int c=nc; c<nc+i; c++){
                map[r][c] = 0;
            }
        }
        paper[i] += 1;

        // 2) 다음 좌표가 1인 곳으로 이동
        dfs(nr, nc, cnt+1);
        
        // 3) 실패해서 돌아왔을 때, 이전에 붙인 색종이 떼기 (0 --> 1)
        for(int r=nr; r<nr+i; r++){
            for(int c=nc; c<nc+i; c++){
                map[r][c] = 1;
            }
        }
        paper[i] -= 1;
    }
}


int main(){

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> map[i][j];
        }
    }
    
    dfs(0, 0, 0); // 한 개도 탐색못함

    if(ans == 1e9)  // 갱신 안됨 <-- 불가능한 경우
        cout << "-1";
    else 
        cout << ans;

    return 0;
}
