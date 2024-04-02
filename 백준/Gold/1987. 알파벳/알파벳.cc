#include <iostream>
#include <set>
using namespace std;

int R, C;
char map[20][20];
int ans = 0;
bool visited[20][20];
bool alphabet[26];

// 상 우 하 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void func(int row, int col, int cnt){
    
    ans = max(ans, cnt);
    
    for(int i=0; i<4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];
        
        int idx = map[nr][nc] - 'A';
        
        if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || alphabet[idx])
            continue;
        
        visited[nr][nc] = true;
        alphabet[idx] = true;    
        func(nr, nc, cnt + 1);
        visited[nr][nc] = false;
        alphabet[idx] = false;
 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        string str; cin >> str;
        
        for(int j=0; j<C; j++){
            map[i][j] = str[j];
        }
    }

    int idx = map[0][0] - 'A';
    visited[0][0] = true;
    alphabet[idx] = true;
    
    // string s = "" + map[0][0] 또는 string s = map[0][0] 잘못된 값 저장됨
    
    func(0, 0, 1);
    
    cout << ans;

    return 0;
}
