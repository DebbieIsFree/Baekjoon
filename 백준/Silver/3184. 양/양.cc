#include <iostream>
#include <queue>
using namespace std;

char arr[250][250];

int rowDir[] = {0, 0, -1, 1};
int colDir[] = {-1, 1, 0, 0};

int R,C;
bool visited[250][250];

int sheep = 0;
int wolf = 0;

void bfs(int row, int col){
    
    int sh = 0;
    int w = 0;
    queue<pair<int, int>> q;
    
    q.push({row,col});
    
    
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        if(arr[row][col] == 'v'){
           w++;
        }
        else if(arr[row][col] == 'o'){
            sh++;;
        }
        
        for(int i=0; i<4; i++){
            int nrow = row + rowDir[i];
            int ncol = col + colDir[i];
            
            if(nrow < 0 || nrow >= R || ncol < 0 || ncol >= C)
                continue;
                
            if(visited[nrow][ncol])
                continue;
                
            if(arr[nrow][ncol] == '.' || arr[nrow][ncol] == 'v' ||
                arr[nrow][ncol] == 'o'){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
            }
        }
    }
    
    if(sh <= w){
        sheep -= sh;
    }
    else if(w>0 && sh > w){
        wolf -= w;
    }
}


int main(){
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'o')
                sheep++;
            else if(arr[i][j] == 'v')
                wolf++;
            else if(arr[i][j] == '#')
                visited[i][j] = true;
        }
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if (!visited[i][j]){
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }
    
    cout << sheep << " " << wolf;
    
    return 0;
}
