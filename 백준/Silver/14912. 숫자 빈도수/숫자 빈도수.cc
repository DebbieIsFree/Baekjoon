#include <iostream>
using namespace std;


int main(){
    
    int N, number;
    cin >> N >> number;
    
    int res = 0;
    
    for(int i=1; i<=N; i++){
        int tmp = i;
        
        int cnt = 0;
        
        while(tmp > 0){
            if(tmp % 10 == number){
                cnt++;
            }
            tmp = tmp / 10;
        }
    
        res += cnt;
    }
   
    cout << res;

    return 0;
}
