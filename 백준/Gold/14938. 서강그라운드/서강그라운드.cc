#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

// 지역 개수, 수색범위, 길의 개수 
int n, m, r;
int dist[101][101];
int items[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    
    for(int i=1; i<=n; i++){
        cin >> items[i];
    }
    
    // dist (모든 노드 N에 대해 임의의 노드 a에서 임의의 노드 b로 가는 최단 거리)
    // INF로 초기화
    fill(&dist[0][0], &dist[100][101], INF);
    
    // 자기 자신으로 가는 거리는 0이다.
    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }

    for(int i=0; i<r; i++){
        int a, b, l;
        cin >> a >> b >> l;
        
        if(l < dist[a][b]){
            // 양방향 그래프
            dist[a][b] = l;
            dist[b][a] = l;    
        }
    }
    
    //플로이드 워셜 (중간, 출발, 도착 순서!!)
    for(int i=1; i<=n; i++){            // 중간에거쳐가는 곳
        for(int j=1; j<=n; j++){        // 출발
            for(int k=1; k<=n; k++){    // 도착
                if(dist[j][i] + dist[i][k] < dist[j][k]){
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<=n; j++){  
            if(dist[i][j] <= m){
                tmp += items[j];
            }
        }
        if(ans < tmp)
            ans = tmp;
    }

    cout << ans;

    return 0;
}

