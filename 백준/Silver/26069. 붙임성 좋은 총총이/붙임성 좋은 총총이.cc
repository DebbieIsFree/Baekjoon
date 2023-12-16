#include <iostream>
#include <set>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    bool flag = false;
    
    set<string> s;
    
    while(N--){
        string n1, n2;
        cin >> n1 >> n2;
        
        if(n1 == "ChongChong" || n2 == "ChongChong"){
            s.insert(n1);
            s.insert(n2);
        }
        
        if(s.find(n1) != s.end() || s.find(n2) != s.end()){
            s.insert(n1);
            s.insert(n2);
        }
    }
    
    cout << s.size();

    return 0;
}
