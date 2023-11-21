#include <iostream>

using namespace std;

int main(){
    
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str; cin >> str;
    
    int cur = 1;
    
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'A'){
            if(cur == 1){
                cur = 2;
            }else if(cur == 2){
                cur = 1;
            }
        }
        else if(str[i] == 'B'){
            if(cur == 2){
                cur = 3;
            }else if(cur == 3){
                cur = 2;
            }
        }
        else if(str[i] == 'C'){
            if(cur == 1){
                cur = 3;
            }else if(cur == 3){
                cur = 1;
            }
        }
    }
    
    cout << cur;

    return 0;
}
