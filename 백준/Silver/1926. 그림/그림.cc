#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[501][501];
bool visited[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> vec;
int num = 0;

void dfs(int x, int y, int &cnt){
    visited[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 1 || nx > 500 || ny < 1 || ny > 500)
            continue;
        if(!visited[nx][ny] && map[nx][ny]){
            dfs(nx, ny, cnt);
        }
    }
    
    vec.push_back(cnt);
}

int main(){
   ios_base::sync_with_stdio(false);  cin.tie(nullptr);
   
   int n, m;    
   cin >> n >> m;   
   
   for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           cin >> map[i][j];
       }
   }
   
   for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
           if(!visited[i][j] && map[i][j]){
               int cnt = 0;
                num++;
                dfs(i, j, cnt);  
           }
       }
   }
   
   vec.push_back(0);
   
   sort(vec.begin(), vec.end(), greater<int>());
   
   
   cout << num << "\n" << vec[0];
    
    return 0;
}










