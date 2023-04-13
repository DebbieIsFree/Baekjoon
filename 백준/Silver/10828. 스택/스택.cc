#include <iostream>
using namespace std;

int MAX = 10000;
int st[10000];

int main(){
    int N;  cin >> N;
    int cur = -1;
    
    while(N--){
        string cmd; cin >> cmd;
        
       
            if(cmd =="push"){
                int num;    cin >> num;
                
                if(cur != MAX){
                    cur++;
                    st[cur] = num;
                }
            }
            else if(cmd == "top") {
                if(cur == -1)
                    cout << "-1\n";
                else cout << st[cur] << '\n';
            }
            else if(cmd == "size") {
                if(cur == -1)
                    cout << "0\n";
                else cout << cur +1 << "\n";
            }
            else if(cmd =="empty"){
                 if(cur == -1)
                    cout << "1\n";
                else cout << "0\n";
            }
            else if(cmd == "pop") {
                 if(cur == -1){
                     cout << "-1\n";
                 }
                  else {
                      cout << st[cur] << '\n';
                      cur--;
                  }
            }
    }
    
    return 0;
}