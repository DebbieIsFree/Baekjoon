#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[1001]; 
vector<pair<int,int>> v[1001];

int main(){
    
    int N, M;   cin >> N;   cin >> M;
    
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back({a, c});      
        // 도시 a에서 b로 가는 비용이 c이므로
        // b에서 a로 가는 것은 처리하면 안된다. (일방향이다.)
    }
    
    int from, to;   cin >> from >> to;
    
    fill_n(dist, 1001, 1e9);
    
    priority_queue<pair<int, int>> pq;
    
    dist[from] = 0;
    pq.push({0, from});
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(dist[now] < cost)
            continue;
            
        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i].first;
            int next_cost = v[now][i].second;
            int cst = cost + next_cost;
            
            if(cost + next_cost < dist[next]){
                dist[next] = cost + next_cost;
                pq.push({cst, next});
            }
        }
    }

    cout << dist[to];
    
    return 0;
}




