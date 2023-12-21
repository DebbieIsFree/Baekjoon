#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[100];


int main(){
    
    int N;  cin >> N;
    int g1, g2;   cin >> g1 >> g2;
    int m; cin >> m;
    
    vector<vector<int>> v(N+1);
    
    while(m--){
        int parent, child;
        cin >> parent >> child;
        v[parent].push_back(child);
        v[child].push_back(parent);
    }
    
    queue<pair<int, int>> q;    // cur_node, count
    q.push({g1,0});

    while(!q.empty()){
        pair<int,int> now = q.front(); q.pop();
        int cnt = now.second;
        visited[now.first] = true;
        
        if(now.first == g2){
            cout << cnt;
            return 0;
        }
        
        bool flag = false;
        
        for(int i=0; i<v[now.first].size(); i++){
            int next = v[now.first][i];
            
            if(visited[next])
                continue;
            flag = true;
            q.push({next, cnt+1});
        }
    }

    cout << "-1";
    
    return 0;
}



