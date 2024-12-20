#include <iostream>
using namespace std;

int N, M;
int arr[100001];
int sum[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<=N; i++){
        sum[i] = (sum[i-1] + arr[i]);
    }
    
    while(M--){
        int i, j;
        cin >> i >> j;
        
        cout << sum[j] - sum[i-1] << "\n";
    }
    
    return 0;
}