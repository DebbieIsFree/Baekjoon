#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, X;
int dist[1001];
vector<vector<pair<int ,int>>> edges(1001);
int res[1001];  

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});        // {cost, node}
    dist[start] = 0;
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        for(int i=0; i<edges[cur].size(); i++){
            int next = edges[cur][i].first;
            int nextCost = edges[cur][i].second;
            
            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;
    
    for(int i=0; i<M; i++){
        int s, e, t;
        cin >> s >> e >> t;
        edges[s].push_back({e, t});
    }
    
    for(int i=1; i<=N; i++){
        fill_n(dist, 1001, INF);
        dijkstra(i);
        res[i] += dist[X];
    }

    fill_n(dist, 1001, INF);
    dijkstra(X);
    
    for(int i=1; i<=N; i++){
        res[i] += dist[i];
    }
    
    cout << *max_element(res, res + 1001);
    
    return 0;
}