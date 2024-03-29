#include <iostream>

using namespace std;

int N, M;
bool visited[9];
int arr[8];

void dfs(int count){        
    if(count == M){     // M개를 다 뽑았다면
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                visited[i] = true;
                arr[count] = i;
                dfs(count+1);
                visited[i] = false;
            }
        }
    }
}



int main(){
    
    cin >> N >> M;
    
    dfs(0);     // 현재 개수 0개
    

    return 0;
}
