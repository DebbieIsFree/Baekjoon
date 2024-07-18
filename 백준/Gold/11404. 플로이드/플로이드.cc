#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int dist[101][101];

void floyd(){
    for(int m=1; m<=N; m++){
        for(int s=1; s<=N; s++){
            for(int e=1; e<=N; e++){
                if(dist[s][e] > dist[s][m] + dist[m][e])  
                    dist[s][e] = dist[s][m] + dist[m][e];
            }
        }
    }
}

int main(){
    cin >> N;
    cin >> M;
    
    int s, e, c;
    
    fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);
    
    for(int i=0; i<M; i++){
        cin >> s >> e >> c;
        
        if(dist[s][e] != INF && dist[s][e] < c)
            continue;
            
        dist[s][e] = c;
    }

    floyd();
    
    for(int s=1; s<=N; s++){
        for(int e=1; e<=N; e++){
            if(dist[s][e] == INF || s == e)
                cout << "0 ";
            else 
                cout << dist[s][e] << " ";
        }
        cout << "\n";
    }

    
    return 0;
}