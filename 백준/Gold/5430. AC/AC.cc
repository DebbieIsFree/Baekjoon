#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;  cin >> T;
    
    while(T--){
        string cmd;      cin >> cmd;
        int n;           cin >> n;
        string nums;     cin >> nums;
        
        vector<string> v;
        
        string tmp = "";
        for(int i=1; i<nums.length(); i++){
            if((nums[i] == ',' || nums[i] == ']') && tmp != ""){
                v.push_back(tmp);
                tmp = "";
            }else{
                tmp += nums[i];
            }
        }
        
        bool flag = false;
        int left = 0;
        int right = v.size() - 1;
        bool isReversed = false;
        
        for(int i=0; i<cmd.length(); i++){
            if(cmd[i] == 'R'){
                isReversed = !isReversed;
            }else if(cmd[i] == 'D'){
                if(left >= v.size() || right < 0 || v.size() == 0){
                    flag = true;
                    break;
                }else if(!isReversed){
                    left = left + 1;
                }else if(isReversed){
                    right = right - 1;
                }
            }
        }
        
        if(flag){
            cout << "error\n";
            continue;
        }
        
        if(isReversed){
            cout << "[";
            for(int i=right; i>=left; i--){
                cout << v[i];
                if(i != left)
                    cout << ",";
            }
            cout << "]\n";
        }
        else{
            cout << "[";
            for(int i=left; i<=right; i++){
                cout << v[i];
                if(i != right)
                    cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}