#include <iostream>

using namespace std;

int arr[1000][1000];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    int R;  cin >> R;
    
    int t = 0;
    
    arr[a][b] = 1;
    
    while(1){
        // for(int i=0; i<R; i++){
        //     for(int j=0; j<=i; j++){
        //         if(arr[i][j] == 2){
        //             cout << t;
        //             return 0;
        //         }
        //     }
        // }
        
        if(arr[a][b] == 2){
            cout << t;
            return 0;
        }
        
        t++;
        
        if(a+1+b+1 < R){
            a += 1;
            b += 1;
            arr[a][b] += 1;
        }
        else{
            a /= 2;
            b /= 2;
            arr[a][b] += 1;
        }
    }

    return 0;
}
