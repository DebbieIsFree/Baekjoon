#include <iostream>

using namespace std;

int N;  
char map[100][100];
bool garoVisited[100][100];
bool seroVisited[100][100];

bool seroDFS(int row, int col, bool visited[100][100], int count){
    bool result = false;
    
    if(count >= 2){
        result = true;
    }
    
    if(row + 1 < N){ 
        if(map[row+1][col] == 'X')
            return result;
        
        if(!visited[row+1][col]){
            visited[row+1][col] = true;
            result = seroDFS(row+1, col, visited, count+1);
        }
    }
    return result;
}


bool garoDFS(int row, int col, bool visited[100][100], int count){
    bool result = false;
    
    if(count >= 2){
        result = true;
    }
    
    if(col + 1 < N){ 
        if(map[row][col+1] == 'X')
            return result;
        
        if(!visited[row][col+1]){
            visited[row][col+1] = true;
            result = garoDFS(row, col+1, visited, count+1);
        }
    }
    return result;
}


int main(){
    cin >> N;
    
    for(int row=0; row<N; row++){
        string str; cin >> str;
        
        for(int col=0; col<N; col++){
            map[row][col] = str[col];
        }
    }

    int garo = 0;
    int sero = 0;
    
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            if(map[row][col] == '.' && !seroVisited[row][col]){
                seroVisited[row][col] = true;
                bool resSero = seroDFS(row, col, seroVisited, 1);
                if(resSero)
                    sero++;
            }
            if(map[row][col] == '.' && !garoVisited[row][col]){
                garoVisited[row][col] = true;
                bool resGaro = garoDFS(row, col, garoVisited, 1);
                if(resGaro)
                    garo++;
            }
        }
    }
    
    
    cout << garo << " " << sero;

    return 0;
}

