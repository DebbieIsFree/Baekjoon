#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int>> v[50001];
int dist[50001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    
    priority_queue<pair<int,int>> q;    
    
    fill(dist, dist+50001, 987654321);
    
    dist[1] = 0;
    q.push({0, 1});
    
    while(!q.empty()){
        int now = q.top().second; 
        int c = -q.top().first;   
        q.pop();
        
        if(dist[now] < c)
            continue;
        
        for(int i=0; i<v[now].size(); i++){     // 현재 노드와 연결된 그 다음 노드
            int next = v[now][i].first;
            int cst = c + v[now][i].second;
            
            if(cst < dist[next]){
                dist[next] = cst;
                q.push({-cst, next});
            }
        }
    }
    
    cout << dist[N] << "\n";

    return 0;
}









