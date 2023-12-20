#include <iostream>
#include <algorithm>
using namespace std;

int arr[30000];

int main(){
    
    int N;  cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int ans = 0;

    for(int i=0; i<N; i++){
        int cnt = 0;
        for(int j=i+1; j<N; j++){
            if(i == j)
                continue;
            if(arr[i] <= arr[j])
                break;
            else
                cnt++;
        }
        ans = max(ans, cnt);
    }
    
    cout << ans;
    
    return 0;
}
