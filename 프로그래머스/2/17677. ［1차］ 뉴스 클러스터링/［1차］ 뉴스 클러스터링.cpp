#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    map<string, int> m1;
    map<string, int> m2;
    
    for(int i=0; i<str1.length()-1; i++){
        string tmp = "";
        if(('A' <= str1[i] && str1[i] <='Z') && ('A' <= str1[i+1] && str1[i+1] <= 'Z')){
            tmp += str1[i];
            tmp += str1[i+1];
            m1[tmp] += 1;   
        }
    }
    
    for(int i=0; i<str2.length()-1; i++){
        string tmp = "";
        if(('A' <= str2[i] && str2[i] <= 'Z') && ('A' <= str2[i+1] && str2[i+1] <= 'Z')){
            tmp += str2[i];
            tmp += str2[i+1];
            m2[tmp] += 1;
        }
    }
    
    int cm = 0;
    int un = 0;
    
    map<string,int>::iterator iter = m1.begin();
    
    while(iter != m1.end()){
        string str = (*iter).first;
        int cnt = (*iter).second;
            
        if(m2.find(str) != m2.end()){
            int minN = min(m1[str], m2[str]);
            cm += minN;
            // un += (maxN-minN);
            if(m1[str] > minN)
                un += (m1[str] - minN);
            if(m2[str] > minN)
                un += (m2[str] - minN);
        }else{
            un += cnt;
        }
        iter++;
    }
    
    iter = m2.begin();
    
    while(iter != m2.end()){
        string str = (*iter).first;
        int cnt = (*iter).second;
            
        if(m1.find(str) == m1.end()){
            un += cnt;
        }
        iter++;
    }
    
    un += cm;
    double calc = (double)cm / (double)un;
    
    if(m1.size() == 0 && m2.size() == 0)
        answer = 65536;
    else
        answer = calc * 65536;
    
    return answer;
}