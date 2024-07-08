#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 987654321;
bool visited[50];
vector<string> words;

void func(string curStr, string target, int cnt){
    if(curStr == target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        if(visited[i])
            continue;
        
        int tmp = 0;
        
        for(int j=0; j<words[i].length(); j++){
            if(words[i][j] != curStr[j])
                tmp++;
            
        }
        
        if(tmp > 1)
            continue;
        
        visited[i] = true;
        func(words[i], target, cnt+1);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> input) {
    sort(words.begin(), words.end());
    words = input;
    
    func(begin, target, 0);
    
    if(answer == 987654321)
        answer = 0;
    
    return answer;
}