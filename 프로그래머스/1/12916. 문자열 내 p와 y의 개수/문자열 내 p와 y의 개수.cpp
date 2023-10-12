#include <string>
#include <iostream>
using namespace std;

bool solution(string s){
    bool answer = true;

    int pn = 0, yn=0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'p' || s[i] == 'P')
            pn++;
        else if(s[i] == 'y' || s[i] == 'Y')
            yn++;
    }
    
    pn == yn ? answer = true : answer = false;
    
    return answer;
}