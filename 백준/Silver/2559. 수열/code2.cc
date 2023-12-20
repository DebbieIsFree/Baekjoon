#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N+1);
    vector<int> arr(N+1);
    
    for(int i=1; i<=N; i++){
        cin >> v[i];
        if(i==1){
            arr[1] = v[1];
        }
        else{
            arr[i] = arr[i-1] + v[i];
        }
    }
    
    int res = -987654321;
    
    int left = 0;
    int right = 0;
    
    while(left <= right && (left <=N && right <= N)){
        if(right - left != K){
            right++;
        }
        else {
            if(res < arr[right] - arr[left])
                res = arr[right] - arr[left];
            
            left++;
            right++;
        }
    }
    
    cout << res;

    return 0;
}
