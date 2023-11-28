#include <iostream>

using namespace std;

int main(){
    
    int N;  cin >> N;
    
    int ans = 0;
    
    for(int i=1; i<=N; i++){
        int n = i;
        while(n > 0){
            int tmp = n % 10;
            if(tmp != 0 && (tmp % 3) == 0){
                ans++;
            }
            n = n / 10;
        }
    }
    
    cout << ans;

    return 0;
}
