#include <iostream>
using namespace std;

int parent[500'000];

int find(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool isSet(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    
    return aRoot == bRoot;
}

void unionSet(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);
    
    if(aRoot < bRoot)
        parent[bRoot] = aRoot;
    else 
        parent[aRoot] = bRoot;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        
        if(isSet(a, b)){
            cout << i;
            return 0;
        }
        else {
            unionSet(a, b);
        }
    }

    cout << "0";
    
    return 0;
}

