#include<vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > maps){
    int answer = -1;
    
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;
    
    int n = maps.size()-1;
    int m = maps[0].size()-1;
   
    if(maps[n][m-1] == 0 && (maps[n-1][m-1] == 0 && maps[n-1][m] == 0))
        return answer;
    
    vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
    
    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if(cx == n && cy == m){
            answer = visited[cx][cy];
            return answer;
        }
        
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if(visited[nx][ny] == 0 && maps[nx][ny] == 1 ){
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    
//     if(visited[n][m] == 0)
//         answer = -1;
    
    return answer;
}