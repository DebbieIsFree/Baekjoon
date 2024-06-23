#include <iostream>
using namespace std;

int T;
int fibo[41][2];

int main(){
    cin >> T;
    
    fibo[0][0] = 1;    
    fibo[1][1] = 1;
    
    for(int i=2; i<=40; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }
    
    while(T--){
        int N;  cin >> N;
        
        cout << fibo[N][0] << " " << fibo[N][1] << "\n";
    }
    

    return 0;
}