#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int arr[101] = {0,};
    
    int m = 0;
    
    for(int i=0; i<3; i++){
        int s, e;
        cin >> s >> e;
        for(int j=s; j<e; j++){
            arr[j] += 1;
        }
        if(m < e)
            m = e;
    }
    
    int sum = 0;
    for(int i=1; i<=m; i++){
        if(arr[i] == 1){
            sum += a;
        }
        else if(arr[i] == 2){
            sum += b*2;
        }
        else if(arr[i] == 3){
            sum += c*3;
        }
    }
    
    cout << sum;
    
    
    return 0;
}





