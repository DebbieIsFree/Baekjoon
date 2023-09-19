#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string tmp = to_string(n);
    vector<int> v;
    
    for(int i=0; i<tmp.length(); i++){
        v.push_back(tmp[i]);
    }
    
    sort(v.begin(), v.end(), greater<int>());
        
    string s = "";
    for(int i=0; i<tmp.length(); i++){
        s += v[i];
    }
    
    answer = stol(s);
    
    return answer;
}