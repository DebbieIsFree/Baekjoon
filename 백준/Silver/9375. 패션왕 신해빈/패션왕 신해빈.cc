#include <iostream>
#include <map>
using namespace std;

int main(){
    int T;  cin >> T;
    
    while(T--){
        int N;  cin >> N;
        
        map<string, int> m;
        
        while(N--){
            string item, category;
            cin >> item >> category;
            
            m[category] += 1;
        }
        
        map<string, int>::iterator iter;
        
        int ans = 1;
        
        for(iter = m.begin(); iter != m.end(); iter++){
            ans = ans * ((*iter).second + 1);
        }
        
        if(m.size() == 0){
            cout << "0\n";
        }
        else{
            cout << ans-1 << "\n";
        }
    }

    return 0;
}