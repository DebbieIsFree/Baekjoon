#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int cnt = 0;
vector<int> coin;

int main(){
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        int n;  cin >> n;
        coin.push_back(n);
    }
    
    sort(coin.begin(), coin.end(), greater<int>());
    
    for(int i=0; i<N; i++){
        cnt += (K / coin[i]);
        K = K % coin[i];
    }
    
    cout << cnt;

    return 0;
}