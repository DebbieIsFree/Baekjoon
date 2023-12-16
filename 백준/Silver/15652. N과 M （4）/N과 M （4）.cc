#include <iostream>
#include <vector>
using namespace std;

int N, M;

void backtrack(int cnt, int cur, vector<int> v){
    if(cnt == M){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout  << "\n";
        return;
    }
        
    for(int i=1; i<=N; i++){
        if(cur > i){
            continue;
        }
        else{
            v.push_back(i);
            backtrack(cnt+1, i, v);
            v.pop_back();  
        }
    }
}

int main(){
    cin >> N >> M;
    
    vector<int> v;
    
    for(int i=1; i<=N; i++){
        v.push_back(i);
        backtrack(1, i, v);
        v.pop_back();
    }
    
    return 0;
}
