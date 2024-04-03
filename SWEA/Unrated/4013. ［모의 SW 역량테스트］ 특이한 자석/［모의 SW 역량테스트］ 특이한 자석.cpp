#include <iostream>
#include <cmath>
using namespace std;

// 전체 톱니바퀴 4개에 대해 
// 작은 번호 톱니바퀴 (인덱스 2) 와 큰 번호 톱니 바퀴 (인덱스 6)을 비교해서
// 회전 방향을 배열에 저장

// 전체를 한꺼번에 회전

int map[4][8];   

// 회전 정보 저장
int direction[4];

bool visited[4];

void getDirection(int idx, int dir){
    // return문 넣으면 안됨
    // if(idx == 0 || idx == 3)
    //     return;
    
    if(idx-1 >=0 && !visited[idx-1]){  // 현재(idx)기준 왼쪽편
        if(map[idx][6] == map[idx-1][2]){
            for(int i=idx-1; i>=0; i--){
                direction[i] = 0;
                visited[i] = true;
            } 
        }
        else{
            direction[idx-1] = -1*dir;
            visited[idx-1] = true;
            getDirection(idx-1, -1*dir);
        }
    }
    if(idx+1 <=3 && !visited[idx+1]){ // 현재(idx)기준 오른쪽편
        if(map[idx][2] == map[idx+1][6]){
            for(int i=idx+1; i<=3; i++){
                direction[i] = 0;
                visited[i] = true;
            }    
        }
        else{
            direction[idx+1] = -1*dir;
            visited[idx+1] = true;
            getDirection(idx+1, -1*dir);
        }
    }
}

void rotate(){
    for(int i=0; i<4; i++){
        int copiedArr[8];
        
        for(int k=0; k<8; k++)
            copiedArr[k] = map[i][k];
        
        if(direction[i] == -1){ // 반시계 회전
            for(int j=0; j<=7; j++){
                map[i][j] = copiedArr[(j+1) % 8];
            }
        }
        else if(direction[i] == 1){    // 시계 회전 
            for(int j=0; j<=7; j++){
                map[i][(j+1) % 8] = copiedArr[j];
            }
        }
    }
}

int main(){
    int T;  cin >> T;
    
    for(int tc=1; tc<=T; tc++){
        int K; cin >> K;    // 회전 횟수
        
        
        // 톱니바퀴 4개의 초기 값이 입력됨 
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0; i<K; i++){
            // 회전 방향 정하기 (0: 회전x, -1: 반시계, 1:시계)
            
            int idx, dir;
            cin >> idx >> dir;  // 회전 시키려는 번호, 회전 방향
            
            idx -= 1;
            
            fill_n(visited, 4, 0);
            fill_n(direction, 4, 0);
            
            visited[idx] = true;
            direction[idx] = dir;
            
            getDirection(idx, dir);
            
            // 4개 한꺼번에(동시에) 회전
            rotate();
        }
        
        int sum = 0;
        for(int i=0; i<4; i++){
            if(map[i][0] == 1)
                sum += pow(2, i);
        }
        
        cout << "#" << tc << " " << sum << "\n";
    }

    return 0;
}



