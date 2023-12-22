#include <iostream>
#include <vector>
using namespace std;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int row, col;  
char arr[600][600];
bool visited[600][600];
int cnt = 0;

void dfs(int cur_row, int cur_col){
    visited[cur_row][cur_col] = true;
    
    if(arr[cur_row][cur_col] == 'P'){
        cnt++;
    }
    
    for(int i=0; i<4; i++){
        int nrow = cur_row + dr[i];
        int ncol = cur_col + dc[i];
        
        if(nrow < 0 || nrow >= row || ncol < 0 || ncol >= col)
            continue;
        if(!visited[nrow][ncol] && (arr[nrow][ncol] == 'O' || arr[nrow][ncol] == 'P')){
            dfs(nrow, ncol);
        }
    }
}

int main(){
    
    cin >> row >> col;
    
    int cr = 0, cc = 0;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'I'){
                cr = i;
                cc = j;
            }
        }
    }
    
    dfs(cr, cc);
    
    if(cnt > 0)
        cout << cnt;
    else
        cout << "TT";
        
    return 0;
}
