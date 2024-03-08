#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9

int N, M;
int dist[101][101];

int main(){
    cin >> N;
    cin >> M;
    
    for(int i=1; i<=N; i++){
        fill_n(dist[i], 101, INF);
    }
    
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c < dist[a][b]){
            dist[a][b] = c;
        }
    }

    for(int i=1; i<=N; i++){    // 거쳐가는 곳
        for(int k=1; k<=N; k++){    // 시작
            for(int j=1; j<=N; j++){    // 도착
                if(k == j){
                    // dist[i][j] = INF;
                    continue;
                }
                if(dist[k][i] + dist[i][j] < dist[k][j]){
                    dist[k][j] = dist[k][i] + dist[i][j];
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
