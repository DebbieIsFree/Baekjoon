#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool flag = false;
vector<int> map[2000];

void dfs(int idx, int cnt, bool visited[]){
    if(flag){
        return;
    }
    
    if(cnt == 5){
        cout << "1";
        flag = true;
        return;
    }
    
    for(int i=0; i<map[idx].size(); i++){
        int node = map[idx][i];

        if(visited[node])
            continue;
            
        // cout << endl << "idx :" << idx << ", node : " << node;    
        // cout << " dfs ";    
        
        visited[node] = true;
        dfs(node, cnt+1, visited);
        visited[node] = false;   
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for(int i=0; i<N; i++){
        bool visited[2000] = {false};
        visited[i] = true;
        dfs(i, 1, visited);
    }
    
    if(!flag)
        cout << "0";

    return 0;
}
