#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;  cin >> N;
    int M;  cin >> M;
    string str; cin >> str;
    
    string findStr = "";
    
    for(int i=1; i<=(N*2)+1; i++){
        if(i % 2 == 1)
            findStr += "I";
        else
            findStr += "O";
    }
    
    int idx = 0;
    int cnt = 0;
    
    while(idx < str.length()){
        int tmp = str.find(findStr, idx);
        
        if(tmp != string::npos){
            cnt++;
            idx = tmp + 1;
        }
        else
            break;
    }
    
    cout << cnt;

    return 0;
}