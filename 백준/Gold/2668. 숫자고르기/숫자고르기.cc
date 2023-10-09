# include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101];
bool visited[101];
bool check[101];
vector<int> v;

void dfs(int start, int cur){
    if(visited[cur] == 0){
        visited[cur] = true;
        dfs(start, arr[cur]);
    }
  
    else if(start == cur){
        v.push_back(cur);
    }
}


int main(){
    
    int N;  cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<=N; i++){
        if(!check[i]){
            dfs(i, i);
            fill(visited, visited+101, false);   
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << v.size() << "\n";
    
    for(int i=0; i<v.size(); i++){  
        cout << v[i] << "\n";
    } 
       
    return 0;
}


