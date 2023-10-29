#include <string>
#include <vector>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[200];
vector<vector<int>> connection;

void dfs(int n, int x);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    connection = computers;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            answer++;
            dfs(n,i);   
        }
    }
    
    return answer;
}

void dfs(int n, int x){    
    
    for(int i=0; i<n; i++){
        if(connection[x][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(n, i);   
        }
    }
}



