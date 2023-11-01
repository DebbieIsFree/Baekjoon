#include <string>
#include <vector>

// 완전탐색 문제
// dfs를 이용해서 풀면 된다.
// Lv2 '피로도' 문제와 유사

using namespace std;

char alph[] = {'A', 'E', 'I', 'O', 'U'};
int ans = 0;
int cnt = 0;

void dfs(string cur_str, string goal){
    if(cur_str == goal)
        ans = cnt;
    
    if(cur_str.length() >= 5)
        return;
    
    for(int i=0; i<5; i++){
        string str = cur_str + alph[i];
        ++cnt;
        dfs(str, goal);
    }
}

int solution(string word) {
    int answer = 0;
    
    string s = "";
    
    dfs(s, word);
    
    answer = ans;
    
    return answer;
}



