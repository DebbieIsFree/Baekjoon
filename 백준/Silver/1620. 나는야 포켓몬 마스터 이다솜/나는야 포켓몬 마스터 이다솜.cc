#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    map<string, string> name;
    map<string, string> num;
    
    for(int i=1; i<=N; i++){
        string str; cin >> str;
        name[str] = to_string(i);
        num[to_string(i)] = str;
    }
    
    while(M--){
        string str;  cin >> str;
        if(name.find(str) != name.end())
            cout << name[str] << "\n";
        else
            cout << num[str] << "\n";
    }

    return 0;
}