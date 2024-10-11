#include <iostream>
using namespace std;

int main(){
    int N;  cin >> N;
    int cnt = 0;
    int cur = 666;
    
    while(true){
        string tmp = to_string(cur);
        
        if(tmp.find("666") != string::npos)
            cnt++;
        
        if(cnt == N)
            break;
        
        cur++;
    }

    cout << cur;

    return 0;
}