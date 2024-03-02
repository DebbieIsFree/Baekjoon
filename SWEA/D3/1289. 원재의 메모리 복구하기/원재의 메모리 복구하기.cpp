#include <iostream>
using namespace std;

int main(){
    int T;  cin >> T;
    
    for(int t=1; t<=T; t++){
        string str; cin >> str;
        int memory[50] = {0,};
        
        int cnt = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] - '0' != memory[i]){
                cnt++;
                for(int j=i; j<str.length(); j++){
                    memory[j] = str[i]-'0';
                }
            }
        }
        cout << "#" << t << " " << cnt << "\n";
    }
    

    return 0;
}
