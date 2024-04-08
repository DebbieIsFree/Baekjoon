#include <iostream>
#include <deque>
#include <string>
using namespace std;

// 틀린 이유 : 
// 문자열 파싱
    // 예외) 한 자리 수 ~ 최대 세 자리 수 (100) 
    // 예외) 숫자 입력 없이 빈 리스트 ([]) 일 때
// deque
// "error" 하고 개행해야 함!

// 수행 함수 p 최대 길이         --> 10^5
// 배열에 들어있는 수 최대 개수  --> 10^5
// 매 수행 함수마다 배열 다 탐색하면 시간초과
// 따라서, R연산 (배열 뒤집기)을 O(N)가 아닌 O(1)으로 풀어야 한다.

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
