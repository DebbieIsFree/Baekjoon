#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int n_max = 0;
    int n_min = 0;
    
    stringstream stream;
    stream.str(s);
    
    vector<int> v;
    string tmp = "";
    while(stream >> tmp){
        int n = stoi(tmp);
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]) + " " + to_string(*(v.end()-1));
    
    
    return answer;
}