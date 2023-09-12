#include <iostream>
#include <queue>
using namespace std;

// bfs 구성은 동생을 찾지 못하면 x+1, x-1, 2x를 visit에 넣어 
// 방문했는지 검사한 후 방문을 하지 않았다면 각각을 q에 넣어주면 간단히 해결된다.

bool visited[100001];
queue<pair<int,int>> que;
int cnt = 0;
int N, K;

void bfs(int cur);

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
   
    cin >> N >> K;
   
    que.push({N, 0});
    visited[N] = true;
    bfs(N);
   
    return 0;
}

void bfs(int cur){
    while(!que.empty()){
        int tmp = que.front().first;
        int count = que.front().second;
        que.pop();
        
        if(tmp == K){
            cout << count;
            break;
        }
        
        if(tmp-1 >=0 && tmp-1 <= 100000){
            if(!visited[tmp-1]){
                que.push({tmp-1, count+1});  
                visited[tmp-1] = true;
            }
        }
        if(tmp+1 >=0 && tmp+1 <= 100000){
            if(!visited[tmp+1]){
                que.push({tmp+1, count+1});
                visited[tmp+1] = true;   
            }
        }
        if(tmp*2 >=0 && tmp*2 <= 100000){
            if(!visited[tmp*2]){
                que.push({tmp*2, count+1});
                visited[tmp*2] = true;   
            }
        }
    }
}

