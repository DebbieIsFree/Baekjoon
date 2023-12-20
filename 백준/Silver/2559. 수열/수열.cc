#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(N + 1, 0);
    vector<int> arr(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    
    for (int i = 1; i <= N; i++) {
        arr[i] = arr[i - 1] + v[i];
    }

    int res = arr[K];
    
    for (int i = K + 1; i <= N; i++) {
        int current_sum = arr[i] - arr[i - K];
        res = max(res, current_sum);
    }
    
    cout << res;

    return 0;
}
