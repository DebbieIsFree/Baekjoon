#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
const int INF = 1e9;
int dist[101][101];

int main(){
    cin >> N >> M;
    
    fill(&dist[0][0], &dist[0][0] + 101*101, INF);
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    // 플로이드 워셜
    for(int i=1; i<=N; i++){          // 중간 거쳐가는 곳
        for(int j=1; j<=N; j++){      // 출발
            for(int k=1; k<=N; k++){  // 도착
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
    
    int m = INF;
    int ans = 1;
    
    for(int i=1; i<=N; i++){
        int sum = 0;
        bool flag = false;
        
        for(int j=1; j<=N; j++){
            if(dist[i][j] == INF){
                flag = true;
                break;
            }
            sum += dist[i][j];
        }
        if(sum < m){
            ans = i;
            m = sum;
        }else if(sum == m && i < ans){
            ans = i;
        }
    }
    
    cout << ans;

    return 0;
}
