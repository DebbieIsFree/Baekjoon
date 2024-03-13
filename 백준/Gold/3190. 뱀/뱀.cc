#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
// #include <priority_queue>

using namespace std;

int N, K, L;

// row, col
queue<pair<int,int>> apple;
// time, dir
priority_queue<pair<int,char>, vector<pair<int, char>>, greater<pair<int, char>>> rot;
// 좌표 (row, col)
deque<pair<int,int>> snake; 

// 상, 하, 좌, 우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool visited[101][101];  // 0 dummy


int main(){
    cin >> N;
    cin >> K;
    
    for(int i=0; i<K; i++){
        int r, c;
        cin >> r >> c;
        apple.push({r, c}); // 사과 위치 입력
    }
    
    cin >> L;
    
    for(int i=0; i<L; i++){
        int t;
        char d;
        cin >> t >> d;
        rot.push({t, d});
    }
    
    int dir = 3;    // 오른쪽
    int r = 1;
    int c = 1;
    int t = 0;
    
    visited[r][c] = true;   // (1,1) 맨 처음 위치  
    snake.push_front({r, c});
    
    while(1){
        t++;
        
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        if(nr < 1 || nr > N || nc < 1 || nc > N || visited[nr][nc])
            break;
        
        visited[nr][nc] = true;
        snake.push_front({nr, nc});
        r = nr;
        c = nc;
        
        bool flag = true;
        
        for(int i=0; i<apple.size(); i++){
            pair<int,int> apl = apple.front();
            apple.pop();
            
            if(apl.first != r || apl.second != c){  // 사과 X --> 꼬리 칸 제거
                apple.push(apl);
            }else{
                flag = false;
                break; 
            }
        }
        if(flag){
            pair<int,int> tmp = snake.back();
            visited[tmp.first][tmp.second] = false;
            snake.pop_back();
        }

        if(!rot.empty()){
            if(rot.top().first == t){
                if(rot.top().second == 'L'){
                    if(dir <= 1)
                        dir = (dir + 2) % 4;
                    else 
                        dir = (dir - 1) % 2;
                }else{
                    if(dir == 0)
                        dir = 3;
                    else 
                        dir = (dir + 1) % 3;
                }
                rot.pop();
            }
        }
    }
    
    cout << t;
    
    return 0;
}

