#include <iostream>

using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    string str;  cin >> str;

    while(M--){
        string tmp;  cin >> tmp;
        
        int cnt = 0;
        int idx = 0;
        int idx2 = 0;
        
        while(1){
            
            if(idx >= tmp.length() || idx2 >= str.length())
                break;
    
            if(str[idx2] == tmp[idx]){
                cnt++;
                idx2++;
            }
            
            idx++;
        }
        
        if(cnt == N){
            cout << "true\n";
        }
        else 
            cout << "false\n";
    }
    
    
    return 0;
}
