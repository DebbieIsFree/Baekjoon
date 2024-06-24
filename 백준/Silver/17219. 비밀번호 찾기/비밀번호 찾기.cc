#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, string> m;

int main(){
    cin >> N >> M;
    cin.ignore();       // getline() 사용하기 전에 cin 입력으로 인한 white-space 없애기
    
    while(N--){
        string str; 
        getline(cin, str);
        stringstream ss(str);
        string word;
        
        string id, pwd;
        int cnt = 0;
            
        while(getline(ss, word, ' ')){
            if(cnt == 0){
                id = word;
                cnt++;
            }else{
                pwd = word;
            }
        }
        m[id] = pwd;
    }

    while(M--){
        string id;  cin >> id;
        cout << m[id] << "\n";
    }

    return 0;
}