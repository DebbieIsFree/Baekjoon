#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define INF 100000001
using namespace std;

int n, m;
int s, e;
vector<vector<pair<int, long long>>> v(1001);
long long dist[1001];

// answer
vector<int> routes;
long long ans = INF;

void dijkstra(int start){
    priority_queue<pair<int, pair<int, vector<int>>>> pq;       // {cost, {node, {route, total}}}
    pq.push({0, {start, {start}}});
    dist[start] = 0;
    
    while(!pq.empty()){
        long long cost = -pq.top().first;
        int cur = pq.top().second.first;
        vector<int> vec = pq.top().second.second;
        pq.pop();
        
        if(dist[cur] < cost)        // 시간초과 에러 해결
            continue;
        
        if(cur == e){
            if(ans > cost){
                ans = cost;
                routes.clear();
                routes = vec;
                break;
            }
        }
        
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;
            
            if(dist[next] > cost + nextCost){
                dist[next] = cost + nextCost;
                
                vector<int> tmp = vec;
                tmp.push_back(next);
                pq.push({-dist[next], {next, tmp}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> m;
    
    for(int i=0; i<m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back({e, c});
    }
    
    cin >> s >> e;
    
    fill_n(dist, 1001, INF);    
    dijkstra(s);
    
    cout << ans << "\n";
    cout << routes.size() << "\n";
    for(int i=0; i<routes.size(); i++){
        cout << routes[i] << " ";
    }

    return 0;
}