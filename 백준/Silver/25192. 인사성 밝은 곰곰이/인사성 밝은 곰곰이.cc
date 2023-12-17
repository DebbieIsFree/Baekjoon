#include <iostream>
#include <set>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    set<string> s;
    
    int res = 0;
    
    while(N--){
        string str;  cin >> str;
        
        
        if(str == "ENTER"){
            res += s.size();
            s.clear();
        }
        else {
            s.insert(str);    
        }
    }
    
    if(!s.empty()){
        res += s.size();
    }
    
    cout << res;
    
    return 0;
}
