#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int M;  cin >> M;
    
    set<int> s;
    
    string cmd; 
    int n;
    
    while(M--){
        cin >> cmd;
        
        if(cmd == "add"){
            cin >> n;
            s.insert(n);
        }
        if(cmd == "remove"){
           cin >> n;
           s.erase(n); 
        }
        if(cmd == "check"){
            cin >> n;
            if(s.find(n) != s.end())
                cout << "1\n";
            else
                cout << "0\n";
        }
        if(cmd == "toggle"){
            cin >> n;
            if(s.find(n) != s.end())
                s.erase(n);
            else
                s.insert(n);
        }
        if(cmd == "all"){
            s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        }
        if(cmd == "empty"){
            s = {};
        }
    }

    return 0;
}