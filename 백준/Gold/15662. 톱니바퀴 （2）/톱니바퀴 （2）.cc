#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dir[1001];  // 0 dummy. 0: 회전 불가, 1: 시계, -1 : 반시계
int T, K;   // 톱니바퀴개수, 회전 횟수

// 톱니바퀴 상태
vector<vector<int>> v(1001);   // S, N

bool checked[1001];

// 회전 가능 여부 & 회전 방향
void updateDir(int num, int d){
    // if(num == 1 || num == T)
    //     return;
    
    if(num - 1 >= 1 && !checked[num-1]){
        if(v[num-1][2] != v[num][6]){
            dir[num-1] = -1*d; 
            checked[num-1] = true;
            updateDir(num-1, -1*d);
        }else{
            for(int i=num-1; i>=1; i--){
                checked[i] = true;
                dir[i] = 0;
            }
        }
    }
    if(num + 1 <= T && !checked[num+1]){
        if(v[num][2] != v[num+1][6]){
            dir[num+1] = -1*d; 
            checked[num+1] = true;
            updateDir(num+1, -1*d);
        }else{
            for(int i=num+1; i<=T; i++){
                checked[i] = true;
                dir[i] = 0;
            }
        }
    }
}

// 회전 함수
void rotation(int num, int dir){
    int copied[8];
    
    for(int i=0; i<8; i++){
        copied[i] = v[num][i];
    }
    
    // 시계 방향 
    if(dir == 1){
        for(int i=0; i<=7; i++){
            v[num][(i+1)%8] = copied[i];
        }
    }
    // 반시계 방향
    else if(dir == -1){
        for(int i=0; i<=7; i++){
            v[num][i] = copied[(i+1)%8];
        }
    }
}

int main(){
    cin >> T;
    
    // 톱니바퀴 초기 상태 
    for(int i=1; i<=T; i++){
        string str; cin >> str;
        for(int j=0; j<str.length(); j++){
            v[i].push_back(str[j] - '0');
        }
    }

    cin >> K;
    
    while(K--){ 
        int num, d;
        cin >> num >> d;
        
        fill_n(dir, 1001, 0);
        fill_n(checked, 1001, false);
        
        dir[num] = d;
        checked[num] = true;
        
        updateDir(num, d);
        
        for(int i=1; i<=T; i++){
            rotation(i, dir[i]);
        }
    }
    
    // 12시 방향이 S극인 바퀴 개수
    int cnt = 0;
    
    for(int i=1; i<=T; i++){
        if(v[i][0] == 1)
            cnt++;
    }
    
    cout << cnt;
    
    return 0;
}

