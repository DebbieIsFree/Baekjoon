#include <iostream>
#include <set>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main(){
 
    int T;  cin >> T;
    
    while(T--){
        int N;  cin >> N;
        
        vector<int> arr(N);
        vector<int> tmp(N);
        // int tmp[16] = {0,};
        
        for(int i=0; i<N; i++){
            int n; cin >> n;
            arr[i] = n;
            tmp[i] = n;
        }
        
        set<string> s;
        string str = "";
        int cnt = 0;
        
        while(1){
            cnt++;
            
            if(cnt > 1000){
                cout << "LOOP" << "\n";
                break;
            }
            
            for(int i=0; i<N; i++){
                if(i < N-1){
                    arr[i] = abs(tmp[i] - tmp[i+1]);
                }
                else {
                    arr[i] = abs(tmp[i] - tmp[0]);
                }
                str += to_string(arr[i]);
            }
            
            for(int i=0; i<N; i++){
                tmp[i] = arr[i];   
            }
            
            bool flag = false;
            
            for(int i=0; i<N; i++){
                if(arr[i] != 0){
                    flag = true;
                    break;
                }
            }
    
            if(!flag){
                cout << "ZERO" << "\n";
                break;
            }
            if(s.find(str) != s.end()){
                cout << "LOOP" << "\n";
                break;
            }
            else{
                 s.insert(str);
            }
            str = "";
        }
    }

    return 0;
}




