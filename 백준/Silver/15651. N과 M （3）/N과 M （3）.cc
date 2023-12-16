#include <iostream>
#include <vector>
using namespace std;

int N, M;

void backtracking(int cnt, vector<int>v){
    if(cnt == M){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=N; i++){
        v.push_back(i);
        backtracking(cnt+1, v);
        v.pop_back();
    }
}


int main(){
    
    cin >> N >> M;
    
    vector<int> v;
    
    for(int i=1; i<=N; i++){
        v.push_back(i);
        backtracking(1, v);
        v.pop_back();
    }
    

    return 0;
}
