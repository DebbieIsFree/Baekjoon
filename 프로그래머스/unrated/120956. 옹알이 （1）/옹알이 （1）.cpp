#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> b) {
    int answer = 0;
    
    for(int i=0; i<b.size(); i++){
        string tmp = "";
        string prev = "";
        int cnt = 0;
        
        for(int j=0; j<b[i].length(); j++){
            tmp += b[i][j];
         
            if(tmp == "aya" || tmp =="ma" || tmp =="woo" || tmp=="ye"){
                if(prev != tmp){
                    cnt++;
                    prev = tmp;
                    tmp = "";    
                }
                else {
                    break;
                }        
            }
        }   
        if(tmp != "")
            cnt = 0;
        if(cnt > 0)
            answer++;
    }

    
    
    return answer;
}



