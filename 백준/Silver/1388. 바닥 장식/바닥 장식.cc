#include <iostream>

using namespace std;

char arr[50][50];
bool visited[50][50];

int row_move[] = {-1, 1};
int col_move[] = {1, -1};

int N, M;


void dfs(int row, int col){
    visited[row][col] = true;
    
    if(arr[row][col] == '-'){
        for(int i=0; i<2; i++){
            int new_col = col + col_move[i];
            
            if(row < 0 || row >= N || new_col <0 || new_col >= M)
                continue;
            
            if(!visited[row][new_col] && arr[row][new_col] == '-'){
                dfs(row, new_col);
            }
        }
    }
    else {
        for(int i=0; i<2; i++){
            int new_row = row + row_move[i];
            
            if(new_row < 0 || new_row >= N || col < 0 || col >= M)
                continue;
            
            if(!visited[new_row][col] && arr[new_row][col] == '|'){
                dfs(new_row, col);
            }
        }
    }
}

int main(){
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    
    cout << cnt;

    return 0;
}
