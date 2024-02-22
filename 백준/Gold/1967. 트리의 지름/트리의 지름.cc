#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// 1. 임의의 노드 a에서 가장 먼 노드 b를 찾는다.
// 2. 다시 노드 b에서 가장 먼 노드 c를 찾는다.
// 3. b와 c 사이의 거리가 답

int V;
// 노드 번호, 비용
vector<vector<pair<int,int>>> v;
bool visited[10001];
int tmpNode = 0;
int ans = 0;

void dfs(int cur, int sum){
    visited[cur] = true;
    
    if(ans < sum){
        tmpNode = cur;
        ans = sum;
    }

    for(int i=0; i<v[cur].size(); i++){
        int node = v[cur][i].first;
        
        if(visited[node])
            continue;
            
        int cost = v[cur][i].second;
        dfs(node, sum + cost);
    }
}

int main(){
    cin >> V;
    v.resize(V+1);
    
    for(int i=1; i<V; i++){
        int p, c, w;
        cin >> p >> c >> w;
        v[p].push_back({c, w});
        v[c].push_back({p, w});
    }
    
    dfs(1, 0);

    fill_n(visited, 10001, 0);
    ans = 0;
    dfs(tmpNode, 0);
    
    cout << ans;

    return 0;
}

