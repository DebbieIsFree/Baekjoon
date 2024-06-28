#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

int main(){
    int N;  cin >> N;
    
    vector<string> v;
    set<string> s;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        if(s.find(str) == s.end()){
            v.push_back(str);
            s.insert(str);
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}