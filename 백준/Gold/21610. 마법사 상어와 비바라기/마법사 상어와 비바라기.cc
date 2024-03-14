#include <iostream>
#include <queue>
using namespace std;

int N, M;

int arr[50][50];    // 물의 양 정보

// row, col
queue<pair<int,int>> position; // 구름 위치    

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1,};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

// 물복사 버그
int br[] = {-1, -1, 1, 1};
int bc[] = {-1, 1, 1, -1};

int main(){
    cin >> N >> M;
    
    // 초기 물 양 입력
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    // 초기 구름 
    for(int i=N-2; i<=N-1; i++){
        position.push({i, 0});
        position.push({i, 1});
    }
    
    
    while(M--){
        int d, s;
        cin >> d >> s;
        
        bool visited[50][50];
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j] = false;
            }
        }
        
        // 1) 각각의 구름에 대해 d방향으로 s만큼 이동시키기
        while(!position.empty()){
            pair<int,int> tmp = position.front();
            int r = tmp.first;
            int c = tmp.second;
            position.pop();
            
            // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
            for(int m=1; m<=s; m++){
                if(d-1 == 0){  
                    c--;
                    if(c < 0) c = N-1;
                }
                else if(d-1 == 4){  
                    c++;
                    if(c == N) c = 0;
                }
                else if(d-1 == 6){
                    r++;
                    if(r == N) r = 0;
                }
                else if(d-1 == 2){
                    r--;
                    if(r < 0) r = N-1;
                }
                else if(d-1 == 7){
                    r++;
                    c--;
                    if(c < 0) c = N-1;
                    if(r == N) r = 0;
                }
                else if(d-1 == 5){
                    r++;
                    c++;
                    if(r == N) r = 0;
                    if(c == N) c = 0;
                }
                else if(d-1 == 1){
                    r--;
                    c--;
                    if(r < 0) r = N-1;
                    if(c < 0) c = N-1;
                }
                else if(d-1 == 3){
                    r--;
                    c++;
                    if(r < 0) r = N-1;
                    if(c == N) c = 0;
                }
            }
            // 이동한 최종 구름 위치 저장 & 물 양 + 1
            visited[r][c] = true;
            arr[r][c] += 1;
        }
        
        // && 물복사 버그
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]){
                    int cnt = 0;
                    for(int dir=0; dir<4; dir++){
                        int nr = i + br[dir];
                        int nc = j + bc[dir];
                        if(nr < 0 || nr >= N || nc < 0 || nc >= N)
                            continue;
                        if(arr[nr][nc] > 0)
                            cnt++;
                    }
                    arr[i][j] += cnt;
                }
            }
        }
        
        // 5) 새로운 구름  (단, vistied[][]= true인 곳 제외)
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!visited[i][j] && arr[i][j] >= 2){
                    position.push({i, j});
                    arr[i][j] -= 2;     // 구름이 생기는 곳, 물 양 -2
                    if(arr[i][j] < 0)
                        arr[i][j] = 0;
                }
            }
        }
    }
    
    // M번 이동 후 총 합
    int sum = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum += arr[i][j];
        }
    }
    
    cout << sum;

    return 0;
}

