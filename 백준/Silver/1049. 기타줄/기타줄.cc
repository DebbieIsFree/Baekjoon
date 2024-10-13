#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int cost;
    int count;
};


int main(){
    int N, M;
    cin >> N >> M;
    
    vector<Node> v;
    
    for(int i=0; i<M; i++){
        int six, one;
        cin >> six >> one;
        
        v.push_back({six, 6});
        v.push_back({one, 1});
    }
    
    int ans = 0;
    
    while(N > 0){
        int minCost = 987654321;
        int n = 0;
        
        for(int i=0; i<v.size(); i++){
            if(N < 6){
                if(v[i].count == 6){
                    if(minCost > v[i].cost){
                        minCost = v[i].cost;
                        n = 6;
                    }
                }
                else{
                    if(minCost > v[i].cost * N){
                        minCost = v[i].cost * N;
                        n = N;
                    }
                }
            }
            else{
                if(v[i].count == 6)
                    minCost = min(minCost, v[i].cost);
                else
                    minCost = min(minCost, v[i].cost * 6);
                n = 6;
            }
        }
        
        ans += minCost;
        N -= n;
    }
    
    cout << ans;
    
    return 0;
}
