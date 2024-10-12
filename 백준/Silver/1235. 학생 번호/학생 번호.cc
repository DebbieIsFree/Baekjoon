#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N;   cin >> N;
    
    vector<string> v;
    
    for(int i=0; i<N; i++){
        string str; cin >> str;
        v.push_back(str);
    }
    
    int ans = 0;
    int len = v[0].length()-1;
    
    for(int k=0; k<=len; k++){
        map<string, int> m;
        bool flag = false;
         
        for(int i=0; i<N; i++){
            string tmp = "";
            
            for(int j=len; j>=len-k; j--){
                tmp += v[i][j];
            }
            
            if(m.find(tmp) != m.end()){
                flag = true;
                break;
            }else{
                m[tmp] += 1;
            }
        }
        
        if(!flag){
            ans = k+1;
            break;
        }
    }
    
    cout << ans;

    return 0;
}
