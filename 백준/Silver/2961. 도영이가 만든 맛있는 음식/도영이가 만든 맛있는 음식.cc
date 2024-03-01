#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 순열 + 비트마스킹

int N;
// 신맛, 쓴맛
vector<pair<long long, long long>> v;
long long ans = 1e9;

void subset(int idx, int mask){
    if(idx == N){
        long long rs = 1, rss = 0;
        for(int i=0; i<N; i++){
            if(mask & 1 << i){
                rs *= v[i].first;
                rss += v[i].second;
            }
        }
        if(rss != 0)
            ans = min(ans, abs(rs - rss));
        return;
    }
    
    subset(idx+1, mask | 1 << idx);
    subset(idx+1, mask);
}


int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        int s, ss;
        cin >> s >> ss;
        v.push_back({s, ss});
    }

    subset(0, 0);
    
    cout << ans;

    return 0;
}
