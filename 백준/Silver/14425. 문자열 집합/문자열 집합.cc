#include <iostream>
#include <set>
using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    set<string> s;
    
    while(N--){
        string str;
        cin >> str;
        s.insert(str);
    }
    
    int cnt = 0;
    
    while(M--){
        string str;
        cin >> str;
        if(s.find(str) != s.end())
            cnt++;
    }
    
    cout << cnt;

    return 0;
}
