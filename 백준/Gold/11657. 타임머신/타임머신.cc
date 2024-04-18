#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 틀린 이유 : 자료형 (int --> long long)
// 벨만 포드는 전체 과정을 정점의 수만큼 돌리기 때문에, 음수 사이클의 절댓값의 최대 길이가 6천만(6*10^3*10^4)이라면 그 과정을 다시 N(최대500)번 반복하면서 N을 곱한 것만큼 절댓값을 키우게 됩니다.

struct edge{
  int src, dest, cost;  
};

int N, M;
vector<edge> edges;
long long dist[501];

const long long INF = 1e10;

int bellman_ford(){
    dist[1] = 0;    
    
    // 벨만-포드 : O(VE)
    for(int i=0; i<N-1; i++){
        for(auto& edge : edges){
            
            // 시작 정점에서 도달할 수 없는 정점인 경우는 pass
            // 도달할 수 없는 곳(비용:INF)을 거쳐서 가는 비용이
            // 더 작은 값일 수는 없으므르..
            if(dist[edge.src] == INF)
                continue;
            
            // 간선(edge)를 거쳐서 dst에 도달하는 비용이
            // 더 적은 경우 --> 갱신
            if(dist[edge.dest] > dist[edge.src] + edge.cost){
                dist[edge.dest] = dist[edge.src] + edge.cost;
            }
        }
    }
    
    // 음수 가중치 사이클 검사
    // 한 번 더 간선(edge) 검사
        // 만약, 최단 거리 테이블(dist)이 더 작은 값으로 갱신되면
        // 음수 가중치 사이클 (음의 무한) 발생
    for(auto& edge : edges){
        
        // 시작 정점에서 도달할 수 없는 정점 --> pass
        if(dist[edge.src] == INF)
            continue;
        if(dist[edge.dest] > dist[edge.src] + edge.cost){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }

    fill_n(dist, 501, INF);

    int ret = bellman_ford();
    
    if(ret == 0)
        cout << "-1";
    else{
        for(int i=2; i<=N; i++){
            if(dist[i] == INF)
                cout << "-1\n";
            else 
                cout << dist[i] << "\n";
        }
    }

    return 0;
}
