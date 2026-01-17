#include <iostream>
#include <vector>
using namespace std;

struct Info {
  int row;
  int col;
  
  Info(int r, int c){
    row = r;
    col = c;
  }
};

int N, L, R;
int map[50][50];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

vector<Info> v;
bool flag = false;
int days = 0;
int sum = 0;

int dfs(int row, int col, bool visited[50][50]){
    visited[row][col] = true;
    
    int res = sum;
    
    for(int dir=0; dir<4; dir++){
        int nrow = row + dr[dir];
        int ncol = col + dc[dir];
        
        if(nrow < 0 || nrow >= N || ncol < 0 || ncol >= N || visited[nrow][ncol])
            continue;
            
        if(abs(map[row][col] - map[nrow][ncol]) >= L && abs(map[row][col] - map[nrow][ncol]) <= R){
            // flag = true;
            v.push_back(Info(nrow, ncol));
            sum += map[nrow][ncol];
            res = dfs(nrow, ncol, visited);
        }    
    }
    
    return res;
}


int main(){
    cin >> N >> L >> R;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    
    while(true){
        bool visited[50][50] = {0,};
        flag = false;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j])
                    continue;
                
                sum = 0;
                    
                v.push_back(Info(i, j));
                sum += map[i][j];
                int res = dfs(i, j, visited);
                int divd =  (int) (res / v.size());
                
                if(v.size() > 1)
                    flag = true;
                
                // cout << endl << "res : " << res << " divd : " << divd << endl;
                
                for(int k=0; k<v.size(); k++){
                    int row = v[k].row;
                    int col = v[k].col;
                    map[row][col] = divd;
                }
                v.clear();
            }
        }
        if(!flag)
            break;
        else
            days++;
    }
    
    cout << days;
    
    return 0;
}