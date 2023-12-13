#include <iostream>

using namespace std;

int cnt1 = 0, cnt2 = 0;

int fibo1(int n){
    if (n == 1 ||  n == 2)
        return 1;  
    else {
        cnt1++;
        fibo1(n - 1) + fibo1(n - 2);
    }
    return cnt1;
}

int f[41];

int fibo2(int n){
    // f[1] = 1;
    // f[2] = 1;
    
    // for(int i=1; i<=n; i++){
    //     f[i] = f[i - 1] + f[i - 2]; 
    // }
    return n-2;
}


int main(){
    
    int n;  cin >> n;
    
    cout << fibo1(n) + 1 << " " << fibo2(n);

    return 0;
}
