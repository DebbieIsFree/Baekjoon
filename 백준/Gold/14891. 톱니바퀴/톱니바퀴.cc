#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<vector<int>> v(5, vector<int>(8, 0));    // 0 dummy
int direction[5];   // 0:회전x, -1:반시계, 1:시계
bool visited[5];

void rotate(){
    for(int i=1; i<=4; i++){
        int copied[8] = {0,};
        
        if(direction[i] == 1){  // 시계 방향
            for(int j=0; j<8; j++){
                copied[(j+1)%8] = v[i][j];
            }
            for(int j=0; j<8; j++){
                v[i][j] = copied[j];
            }
        }
        else if(direction[i] == -1){   // 반시계 방향
            for(int j=0; j<=7; j++){
                copied[j] = v[i][(j+1)%8];
            }
            for(int j=0; j<8; j++){
                v[i][j] = copied[j];
            }
        }
    }
}

void check(int idx, int dir){
    if(dir == 1 || dir == -1){
        if(idx-1 >= 1){
            if(v[idx-1][2] == v[idx][6] && !visited[idx-1]){
                for(int i=idx-1; i>=1; i--){
                    if(!visited[i]){
                        direction[i] = 0;
                        visited[i] = true;
                    }
                }
                // return;
            }else{
                if(!visited[idx-1]){
                    direction[idx-1] = -1*dir;
                    visited[idx-1] = true;
                    check(idx-1, -1*dir);
                }
            }
        } 
        //
        if(idx+1 <= 4){
            if(v[idx][2] == v[idx+1][6] && !visited[idx+1]){
                for(int i=idx+1; i<=4; i++){
                    if(!visited[i]){
                        direction[i] = 0;
                        visited[i] = true;
                    }
                }
                // return;
            }else{
                if(!visited[idx+1]){
                    direction[idx+1] = -1*dir;
                    visited[idx+1] = true;
                    check(idx+1, -1*dir);
                }
            }
        }
    }
}

int main(){
    for(int i=1; i<=4; i++){
        string str; cin >> str;
        for(int j=0; j<8; j++){
            v[i][j] = str[j] - '0';
        }
    }
    
    int K;  cin >> K;
    
    while(K--){
        int idx, dir;
        cin >> idx >> dir;
        
        fill_n(direction, 5, 0);
        fill_n(visited, 5, false);
        
        direction[idx] = dir;
        visited[idx] = true;
        check(idx, dir);
        rotate();  // 전체 한꺼번에 회전
    }
    
    int sum = 0;
    for(int i=1; i<=4; i++){
        if(v[i][0] == 1){
            sum += pow(2, i-1);
        }
    }
    cout << sum;

    return 0;
}
