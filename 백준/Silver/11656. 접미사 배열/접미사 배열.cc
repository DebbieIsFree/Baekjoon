#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(string s1, string s2){
    return s1 < s2;
}

int main(){
    
    string str; cin >> str;
    
    vector<string> v;
    
    v.push_back(str);
    
    for(int i=1; i<str.length(); i++){
        string tmp = "";
        for(int j=i; j<str.length(); j++){
            tmp += str[j];
        }
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}
