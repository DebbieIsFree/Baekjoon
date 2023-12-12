#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    int m = 0;
    
    for(int i=1; i<=N; i++){
        int n = i;
        
        bool flag = false;
        
        while(n > 0){
            int tmp = n % 10;
            if(tmp == 4 || tmp == 7){
                n = n / 10;
            }
            else {
                flag = true;
                break;
            }
        }
        if(!flag)
            m = i;
    }
    
    cout << m;
    
    return 0;
}
