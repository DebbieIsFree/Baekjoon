#include <string>
#include <vector>

using namespace std;

// 완전탐색 문제
// dfs를 이용해서 풀면된다.

bool visited[8];
int limit = 0;
int ans = 0;

void dfs(int rest, int cnt, vector<vector<int>> dungeons){
    for(int i=0; i<dungeons.size(); i++){
        if(!visited[i] && rest >= dungeons[i][0]){
            visited[i] = true;
            dfs(rest-dungeons[i][1], cnt+1, dungeons);
            visited[i] = false;
        }
        else
            ans = max(ans, cnt);
    }
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    limit = k;    
    
    for(int i=0; i<dungeons.size(); i++){
        if(!visited[i])
            dfs(k, 0, dungeons);
    }
    
    answer = ans;
    
    return answer;
}



