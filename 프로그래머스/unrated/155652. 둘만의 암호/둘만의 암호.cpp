#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    map<char, int> m1;
    map<int, char> m2;
    
    sort(skip.begin(), skip.end());
    
    int idx = 0;
    int n=0;
    for(int i='a'; i<='z'; i++){
        if(i == skip[idx]){
            idx++;
        }else{
            m1.insert({i, n});
            m2.insert({n, i});
            n++;
        }
    }
    
    // cout << endl;
    // for(auto iter : m2){
    //     cout << iter.second << " ";
    // } 
    
    for(int i=0; i < s.length(); i++){
        int tidx = m1[s[i]];
        tidx += index;
        tidx = tidx % n;
        answer += m2[tidx];
    }
    

    // cout << endl << answer;
    
    return answer;
}