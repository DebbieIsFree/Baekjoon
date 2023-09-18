#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<char, int> m;
    for(int i=0; i<terms.size(); i++){
        if(terms[i].length() == 3){
            m[terms[i][0]] = terms[i][2] - '0';   
        }
        else if(terms[i].length() == 4){
            m[terms[i][0]] = (terms[i][2] - '0') * 10 + (terms[i][3] - '0');
        }
        else if(terms[i].length() == 5){
            m[terms[i][0]] = (terms[i][2] -'0') * 100 + (terms[i][3] -'0') * 10 + (terms[i][4] -'0');
        }
    }
  
    string mp = "";
    for(int i=0; i<today.length(); i++){
        if(today[i] == '.' || today[i] == ' ')
            continue;
        else{
            mp += today[i];
        }
    }
    long long tday = stoi(mp);
    
    for(int i=0; i<privacies.size(); i++){
        string tmp = "";
        char term;
        for(int j=0; j<privacies[i].length(); j++){
            if(j == privacies[i].length()-1){
                term = privacies[i][j];
                break;
            }
            if(privacies[i][j] == '.' || privacies[i][j] == ' ')
                continue;
            else{
                tmp += privacies[i][j];
            }
        }
        int date = stoi(tmp);
        
        int tn = date  % 10000;
        date -= tn;
        
        tn = tn + m[term]*100;
        if(tn < 1300){
            date += tn;    
        }
        else{
            while(tn >= 1300){
                date += 10000;
                tn -= 1200;
            }
            date += tn;
        }
        
        if(tday >= date){
            answer.push_back(i+1);
        }
        // cout << endl << i+1 << "번째 date : " << date;
    }
    

    return answer;
}
