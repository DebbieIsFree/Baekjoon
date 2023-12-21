#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;  cin >> n;
    
    set<string> s;
    
    while(n--){
        string name, str; 
        cin >> name >> str;
        
        if(str == "enter"){
            s.insert(name);
        }
        else{
            set<string>::iterator iter = s.find(name);
            if(iter != s.end())
                s.erase(iter);  
        }
    }
    
    vector<string> v;
    v.assign(s.begin(), s.end());
    
    sort(v.begin(), v.end(), greater<string>());
    
    for(auto name : v){
        cout << name << "\n";
    }

    return 0;
}
