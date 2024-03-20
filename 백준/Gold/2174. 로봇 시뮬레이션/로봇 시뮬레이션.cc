#include <iostream>
#include <vector>
using namespace std;

// 문제는 쉬운데, 배열이 뒤집어져 있어서 <그림>을 잘 살펴봐야 한다.

int a, b, n, m; // 가로, 세로, 로봇 개수, 명령어 수

// forward 방향
// 상, 우, 하, 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){
    cin >> a >> b;
    cin >> n >> m;
    
    // <<row, col>, dir>
    vector<pair<pair<int,int>, int>> v(n+1);
    
    // 로봇 정보 입력 
    for(int i=1; i<=n; i++){
        int col, row;
        char dir;
        cin >> col >> row >> dir;
        
        int d = 0;  
        if(dir=='E') d = 1;
        else if(dir=='N') d = 2;     // 상 -> 하
        else if(dir=='S') d = 0;    // 하 -> 상
        else if(dir=='W') d = 3;
        v[i] = {{row, col}, d};
    }
    
    // 명렁어 m번 실행
    for(int i=0; i<m; i++){
        int number, repeat;
        char cmd;
        cin >> number >> cmd >> repeat;
        
        int nr = v[number].first.first;
        int nc = v[number].first.second;
        int dir = v[number].second;
        
        for(int j=0; j<repeat; j++){
            if(cmd == 'R'){
                if(dir%2 == 0)
                    dir = (dir + 3) % 4;
                else
                    dir = (dir - 1) % 4; 
            }else if(cmd == 'L'){
                dir = (dir + 1) % 4;
            }else if(cmd == 'F'){
                nr = nr + dr[dir];
                nc = nc + dc[dir];
            }
            
            if(nr < 1 || nr > b || nc < 1 || nc > a){
                cout << "Robot " << number << " crashes into the wall";
                return 0;
            }
            for(int k=1; k<=n; k++){
                if(k != number && (v[k].first.first == nr && v[k].first.second== nc)){
                    cout << "Robot " << number << " crashes into robot " << k;
                    return 0;
                }
            }
        }
        v[number].first.first = nr;
        v[number].first.second = nc;
        v[number].second = dir;
    }

    cout << "OK";

    return 0;
}

