#include <iostream>
#include <queue>

using namespace std;

int main(){
    std::deque<int> deq; 
    int N;  cin >> N;
    
    while(N--){
        string cmd; cin >> cmd;
        
        if(cmd == "push_front"){
            int val;    cin >> val;
            deq.push_front(val);
        }
        else if(cmd == "push_back"){
            int val;    cin >> val;
            deq.push_back(val);
        }
        else if(cmd == "pop_front"){
            if(!deq.empty()){
                cout << deq.front() << "\n";
                deq.pop_front();   
            }else{
                cout << "-1\n";
            }
        }
        else if(cmd == "pop_back"){
            if(!deq.empty()){
                cout << deq.back() << "\n";
                deq.pop_back();    
            }else{
                cout << "-1\n";
            }
        }
        else if(cmd == "size"){
            cout << deq.size() << "\n";
        }
        else if(cmd == "empty"){
            if(deq.empty()){
                cout << "1\n";
            }else{
                cout << "0\n";
            }
        }
        else if(cmd == "front"){
            if(!deq.empty()){
                cout << deq.front() << "\n";
            }else{
                cout << "-1\n";
            }
        }
        else if(cmd == "back"){
            if(!deq.empty()){
                cout << deq.back() << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }
    
    
    return 0;
}
