#include <iostream>
#include <queue>
using namespace std;

int N, M;
priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;        // {cost, {from, to}}
int parent[1001];
int ans = 0;

void makeSet(){
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
}

int findSet(int x){
    if(x == parent[x])
        return x;
    return parent[x] = findSet(parent[x]);
}


void unionSet(int a, int b){
    int aRoot = findSet(a);
    int bRoot = findSet(b);
    
    if(aRoot < bRoot)
        parent[bRoot] = aRoot;
    else
        parent[aRoot] = bRoot;
}


void kruskal(){
    int cnt = 0;
    
    while(!pq.empty()){
        if(cnt == N-1)
            break;
        
        int cost = pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        
        if(findSet(from) == findSet(to))
            continue;
        
        unionSet(from, to);
        ans += cost;
        cnt++;
    }
}

int main(){
    cin >> N;
    cin >> M;
    
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    
    makeSet();
    
    kruskal();

    cout << ans;

    return 0;
}