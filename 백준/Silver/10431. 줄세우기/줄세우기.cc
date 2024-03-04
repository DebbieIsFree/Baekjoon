#include <iostream>
#include <deque>
using namespace std;

int main(){
    int P;  cin >> P;
    
    for(int t=1; t<=P; t++){
        deque<int> dq, tmp;
        int cnt = 0;
        
        for(int i=1; i<=21; i++){
            int n;  cin >> n;
            if(i == 1)  
                continue;

            if(dq.empty()){
                dq.push_back(n);
            }else{
                while(!dq.empty() && dq.back() > n){
                    tmp.push_front(dq.back());
                    dq.pop_back();
                    cnt++;
                }
                dq.push_back(n);
                while(!tmp.empty()){
                    dq.push_back(tmp.front());
                    tmp.pop_front();
                }
            }
        }
        cout << t << " " << cnt << "\n";
    }


    return 0;
}
