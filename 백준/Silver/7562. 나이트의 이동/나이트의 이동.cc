#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
    
    int t;  cin >> t;
    
    while(t--){
        int n;  cin >> n;
        int cr, cc, gr, gc;
        cin >> cr >> cc;
        cin >> gr >> gc;
        
        int visited[300][300] = {0,};
        
        queue<pair<int,int>> q;
    
        q.push({cr, cc});
        visited[cr][cc] = 0;
        
        while(!q.empty()){
            pair<int,int> now = q.front();
            q.pop();
            
            if(now.first == gr && now.second == gc)
                break;
            
            for(int i=0; i<8; i++){
                int nrow = now.first + dr[i];
                int ncol = now.second + dc[i];
                
                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= n)
                    continue;
                    
                if(!visited[nrow][ncol]){
                    visited[nrow][ncol] = visited[now.first][now.second] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        cout << visited[gr][gc] << "\n";
    }

    return 0;
}
