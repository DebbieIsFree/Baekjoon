#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string solution(string x, string y) {
    string answer = "";
    
    map<int, int> m1;
    map<int, int> m2;
    
    for(int i=0; i<=9; i++){
        m1.insert({i, 0});
        m2.insert({i, 0});
    }
    
    
    for(int i=0; i < x.length(); i++){
        int n = x[i] - '0';
        m1[n] += 1;    
    }
    
    for(int i=0; i < y.length(); i++){
        int n = y[i] - '0';
        m2[n] += 1;
    }
    
    vector<int> v;
    
    for(int i=0; i<=9; i++){
        if(m1[i] > 0 && m2[i] > 0){
            if(m1[i] < m2[i]){
                for(int j=0; j<m1[i]; j++){
                    v.push_back(i);   
                }
            }
            else {
                for(int j=0; j<m2[i]; j++){
                    v.push_back(i);   
                }
            }   
        }
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
     if(v.empty()){
        answer += "-1";
        return answer;
    }
    
    
    if(v[0] == 0){
        answer += '0';
        return answer;
    }
    
    
    for(int i=0; i < v.size(); i++){
        answer += to_string(v[i]);
    }
    
    return answer;
}






