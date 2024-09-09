#include <iostream>
using namespace std;

int main(){
    string str;  cin >> str;
    int cnt = 0;
    string ans = "";
    
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'X'){
            cnt++;
        }else{
            if(cnt % 2 == 0 || cnt % 4 == 0){
                while(cnt != 0){
                    if((cnt - 4) >= 0){
                        ans += "AAAA";
                        cnt -= 4;
                    }else if((cnt-2) >=0){
                        ans += "BB";
                        cnt -= 2;
                    }
                    else {
                        cout << "-1";
                        return 0; 
                    }
                }
                ans += ".";
            }else{
                cout << "-1";
                return 0;
            }
        }
    }
    
    if(cnt % 2 == 0 || cnt % 4 == 0){
        while(cnt != 0){
            if((cnt -4) >=0){
                ans += "AAAA";
                cnt -= 4;
            }else if((cnt-2) >=0){
                ans += "BB";
                cnt -= 2;
            }
            else{
                cout << "-1";
                return 0;    
            }
        }
    }else{
        cout << "-1";
        return 0;
    }
    
    cout << ans;

    return 0;
}