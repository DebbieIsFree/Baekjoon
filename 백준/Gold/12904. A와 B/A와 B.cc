#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    string s, t;
    cin >> s;
    cin >> t;
    
    vector<char> v;
    
    for(auto c : t){
        v.push_back(c);
    }
    
    
    
    while(v.size() != s.length()){
        if(v.back() != 'A' && v.back() != 'B'){
            cout << "0";
            return 0;
        }
        else if(v.back() == 'A'){
            v.pop_back();
        }
        else if(v.back() == 'B'){
            v.pop_back();
            reverse(v.begin(), v.end());
        }
    }


    string str = "";
    for(auto c : v){
        str += c;
    }

    if(str == s)
        cout << "1";
    else 
        cout << "0";

    return 0;
}

