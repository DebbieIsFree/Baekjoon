#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    int T;  cin >> T;
    
    while(T--){
        string cmd; cin >> cmd;
        int n;  cin >> n;
        string input; cin >> input;
        
        deque<int> dq;
        
        string str = "";
        for(int i=0; i<input.length(); i++){
            if(input[i] == ',' || input[i] == ']'){
                if(str != "")
                    dq.push_back(stoi(str));
                str = "";
            }else if(input[i] >= '0' && input[i] <= '9'){
                str += input[i];
            }
        }
        
        bool flag = false;  // reverse가 아닌 상태 
        bool output = false;    // "[ ]" 이렇게 출력할 수 있는 상태
        
        for(int i=0; i<cmd.length(); i++){
            if(cmd[i] == 'R'){
                flag = !flag;
            }
            else {
                if(dq.empty()){
                    cout << "error\n";
                    output = true;
                    break;
                }else{
                    if(!flag){
                        dq.pop_front();
                    }else{
                        dq.pop_back();
                    }
                }
            }
        }
        if(output)
            continue;
        

        cout << "[";
        if(!flag){
            while(!dq.empty()){
                cout << dq.front();
                if(dq.size() > 1){
                    cout << ",";
                }
                dq.pop_front();
            }    
        }else{
            while(!dq.empty()){
                cout << dq.back();
                if(dq.size() > 1){
                    cout << ",";
                }
                dq.pop_back();
            }
        }
        cout << "]" << "\n";
    }

    return 0;
}
