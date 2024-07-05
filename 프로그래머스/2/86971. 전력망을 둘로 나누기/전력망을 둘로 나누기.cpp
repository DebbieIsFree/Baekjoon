#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int answer = 987654321;
vector<vector<int>> wires;

int parent[101];

void makeSet(){
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
}

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    
    if(aRoot < bRoot)
        parent[bRoot] = aRoot;
    else
        parent[aRoot] = bRoot;
}

void func(int idx){
    makeSet();
    
    for(int i=0; i<wires.size(); i++){
        if(i == idx)
            continue;
        
        int a = wires[i][0];
        int b = wires[i][1];
        
        if(find(a) != find(b)){
            unionSet(a, b);
        }
    }
    
    // 경로압축이 제대로 반영 안 됐을 수도 있으니까 한번 더 확인
    for(int i=1; i<=N; i++){
        find(i);
    }
    
    map<int,int> m;
    vector<int> p;
    
    for(int i=1; i<=N; i++){
        if(m.find(parent[i]) == m.end()){
            p.push_back(parent[i]);
        }
        m[parent[i]] += 1;   
    }
    
    if(m.size() == 2)
        answer = min(answer, abs(m[p[0]] - m[p[1]]));
}


int solution(int n, vector<vector<int>> input) {
    wires = input;
    N = n;
    
    // parent[] 배열 초기화
    makeSet();
    
    for(int i=0; i<wires.size(); i++){
        func(i);
    }
        
    return answer;
}