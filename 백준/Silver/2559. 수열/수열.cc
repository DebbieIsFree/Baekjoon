#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N+1, 0);
    vector<int> arr(N+1, 0);
    
    for(int i=1; i<=N; i++){
        cin >> v[i];
    }
    
    for(int i=1; i<=N; i++){
        arr[i] = arr[i-1] + v[i];
    }

    // 각각의 수는 -100 이상 100 이하의 값을 가지므로, N이 최대 10^5일 때 모든 값이 -100보다 큰
    // 숫자로 초기화 한다.
    int res = -987654321;
    
    for (int i=K; i<=N; i++) {
        int tmp = arr[i] - arr[i - K];
        res = max(res, tmp);
    }
    cout << res;

    return 0;
}
