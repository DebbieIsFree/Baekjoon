#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

struct Edge{
  int s, e, c;  
};

int T, N, M, W;        // 정점 개수, 도로 개수, 웜홀 개수
vector<Edge> edges;
int dist[501];

bool bellmanford(int start){
    dist[start] = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<edges.size(); j++){
            int s = edges[j].s;
            int e = edges[j].e;
            int c = edges[j].c;
            
            // if(dist[s] == INF)
            //     continue;
            
            if(dist[e] > dist[s] + c){
                dist[e] = dist[s] + c;
                if(i == N){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    while(T--){
        cin >> N >> M >> W;
        int S, E, T;
        
        // 도로 정보
        for(int i=0; i<M; i++){
            cin >> S >> E >> T;
            // 도로에 방향 X
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        
        //  웜홀 정보
        for(int i=0; i<W; i++){
            cin >> S >> E >> T;
            // 방향 O
            edges.push_back({S, E, -T});
        }
        
        bool flag = false;
        
        fill_n(dist, 501, INF);
        bool res = bellmanford(1);
        
        if(res)
            cout << "NO\n";
        else
            cout << "YES\n";
            
            
        edges.clear();
    }
    
    return 0;
}