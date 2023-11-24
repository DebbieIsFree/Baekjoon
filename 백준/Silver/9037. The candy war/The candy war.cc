#include <iostream>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;  cin >> T;
    
    while(T--){
        int N;  cin >> N;
        
        int arr[10] = {0,};
        int tmp[10] = {0,};
        
        for(int i=0; i<N; i++){
            cin >> arr[i];
            if(arr[i] % 2 != 0){
                arr[i] += 1;
            }
            tmp[i] = arr[i];
        }
        
        int ans = 0;
        
        while(1){
            bool flag = false;
            for(int i=0; i<N-1; i++){
                if(arr[i] != arr[i+1]){
                    flag = true;
                    break;
                }
            }
            
            if(flag == false)
                break;
            
            ans++; 
            
            for(int i=0; i<N; i++){
                if(i == N-1){
                    arr[0] = tmp[0] /2 + tmp[N-1] / 2;
                    if(arr[0] % 2 != 0){
                        arr[0] += 1;
                    } 
                }
                else{
                    arr[i+1] = (tmp[i+1] / 2) + (tmp[i] / 2);     
                    if(arr[i+1] % 2 != 0){
                        arr[i+1] += 1;
                    }
                }
            }
            
            for(int i=0; i<N; i++){
                tmp[i] = arr[i];
            }
        }
        cout << ans << "\n";
    }
    

    
    return 0;
}
