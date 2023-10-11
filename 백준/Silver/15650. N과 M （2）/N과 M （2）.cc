#include <iostream>

using namespace std;

int N, M;
bool visited[9];
int arr[8];

void dfs(int count){
    if(count == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=1; i<=N; i++){
            if(!visited[i]){
                if(count > 0 && arr[count-1] < i){
                    visited[i] = true;
                    arr[count] = i; 
                    dfs(count + 1);
                    visited[i] = false;    
                }
                else if(count == 0){
                    visited[i] = true;
                    arr[count] = i; 
                    dfs(count + 1);
                    visited[i] = false;    
                }
                
            }
        }
    }
}


int main(){
    
    cin >> N >> M;
    
    dfs(0);
    
    return 0;
}
