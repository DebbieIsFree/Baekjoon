#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> v(1001);
bool visited[1001];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        cout << cur << " ";
        
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            
            if(visited[next])
                continue;
            
            visited[next] = true;
            q.push(next);
        }
    }
}

void dfs(int cur){
    visited[cur] = true;
    
    cout << cur << " ";
    
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i];
        
        if(visited[next])
            continue;
            
        visited[next] = true;
        dfs(next);
    }
}

int main(){
    cin >> N >> M >> V;
    
    while(M--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<=N; i++){
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    
    cout << "\n";
    
    fill_n(visited, 1001, false);
    bfs(V);

    return 0;
}