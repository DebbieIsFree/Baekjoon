#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int rmv = 0;
    
    while(true){
        if(s == "1"){
            break;
        }
        
        string tmp = "";
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                tmp += '1';
            }
            if(s[i] == '0'){
                rmv += 1;
            }
        }
        s = tmp;
        cnt++;
        int len = tmp.length();
        string binary = "";
        while(len > 0){
            binary = to_string(len % 2) + binary;
            len = len / 2;
        }
        s = binary;
    }
    
    answer.push_back(cnt);
    answer.push_back(rmv);
    
    
    return answer;
}
