#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
set<int> s;         // 진실을 아는 사람 집합 
vector<vector<int>> party(51);
int parent[51];

void makeSet(){
    for(int i=0; i<=50; i++){
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    int n;  cin >> n;
    
    if(n != 0){
        for(int i=0; i<n; i++){
            int p;  cin >> p;
            s.insert(p);
            parent[p] = 0;
        }
    }
    
    makeSet();

    for(int i=1; i<=M; i++){
        int cnt;    cin >> cnt;
        vector<int> v;
        vector<int> tmp;    // set에 있는, 진실을 아는 사람
        
        for(int j=0; j<cnt; j++){
            int p;  cin >> p;
            party[i].push_back(p);
            v.push_back(p);
            if(s.find(p) != s.end()){
                tmp.push_back(p);
            }
        }
        
        if(!tmp.empty()){
            sort(tmp.begin(), tmp.end());    
            for(int j=0; j<cnt; j++){
                unionSet(0, v[j]);
            }   
        }else{
            sort(v.begin(), v.end());
            int idx = v[0];
            for(int j=0; j<cnt; j++){
                unionSet(idx, v[j]);
            } 
        }
    }
    
    // 경로압축법 한번 더 확인
    for(int i=0; i<=N; i++){
        findSet(i);
    }
    
    // 거짓말이 가능한 파티 개수 세기
    int cnt = 0;
    
    for(int i=1; i<=M; i++){
        bool flag = false;
        
        for(int j=0; j<party[i].size(); j++){
            int idx = party[i][j];
            
            if(parent[idx] == 0){
                flag = true;
                break;
            }
        }
        
        if(!flag)
            cnt++;
    }
    
    cout << cnt;

    return 0;
}