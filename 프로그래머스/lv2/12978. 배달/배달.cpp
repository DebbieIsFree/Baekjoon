#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<pair<int,int>>> graph(51);
    
    int distance[51];
    fill(distance, distance+51, 999999);
    
    queue<pair<int, int>> q;
    
    for(int i=0; i<road.size(); i++){
        int s = road[i][0];
        int e = road[i][1];
        int c = road[i][2];
        
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }
    
    q.push({1, 0});
    distance[1] = 0;
    
    while(!q.empty()){
        int now = q.front().first;
        int now_dist = q.front().second;
        q.pop();
        
        if(distance[now] < now_dist)
            continue;
        
        distance[now] = now_dist;
        
        for(int i=0; i<graph[now].size(); i++){
            int next = graph[now][i].first;
            int cost = now_dist + graph[now][i].second;
            
            if(cost < distance[next]){
                distance[next] = cost;
                q.push({next, cost});
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(distance[i] <= K)
            answer++;
    }
    
    return answer;
}