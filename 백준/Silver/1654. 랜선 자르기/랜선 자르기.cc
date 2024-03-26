#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<long long> v;

int main(){
    cin >> K >> N;

    for(int i=0; i<K; i++){
        int n;  cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    long long standard = v[0];
    long long max_count = 0;
    long long max_len = 0;
    long long left = 1;
    long long right = v[0];

    while(left <= right && standard > 0){
        int mid = (left + right) / 2;
        
        if(mid == 0)
            break;
        
        int tmp = 0;
        for(int i=0; i<v.size(); i++){
            tmp += (v[i] / mid);
        }
            
        if(tmp >= N && max_len < mid){
            max_len = mid;
            left = mid + 1;
        }else if(tmp < N){
            right = mid - 1;
        }
    }

    cout << max_len;

    return 0;
}

