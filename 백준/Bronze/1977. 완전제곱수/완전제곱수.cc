#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    int sum = 0;
    int m = 0;
    bool flag = false;
    
    for(int i=N; i<=M; i++){
        if(int(sqrt(i)) * int(sqrt(i)) == i){
            sum += i;
            if(!flag){
                flag = true;
                m = i;
            }
        }
    }

    if(sum == 0)
        cout << "-1";
    else 
        cout << sum << "\n" << m;

    return 0;
}
