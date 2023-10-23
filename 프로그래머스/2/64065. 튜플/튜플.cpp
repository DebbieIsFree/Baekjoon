#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    queue<int> q;
    vector<vector<int>> v(1000001);
    
    int len = 0;
    
    string tmp = "";
    // 맨 앞 {, 맨 끝 }은 무시
    for(int i=1; i<s.length()-1; i++){
        
        if(s[i] == ',' || s[i] == '}'){
            if(tmp != ""){
                int num = stoi(tmp);
                tmp = "";
                q.push(num);
            }
        }
        if(s[i] == '}'){
            int idx = q.size();
            if(len < idx){
                len = idx;
            }
            while(!q.empty()){
                v[idx].push_back(q.front());
                q.pop();
            }
        }
        else if(s[i] != '{' && s[i] != ','){    // 숫자
            tmp += s[i];
        }
    }
    
    
    
    bool checked[100001] = {0,};
    
    for(int i=1; i<=len; i++){
        for(int j=0; j<v[i].size(); j++){
            int n = v[i][j];
            if(!checked[n]){
                answer.push_back(n);
                checked[n] = true;
            }
        }
    }
    
    return answer;
}



