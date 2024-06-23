#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;  cin >> N;
    
    vector<pair<int,int>> v;    
    
    for(int i=0; i<N; i++){
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }
    
    sort(v.begin(), v.end());   
    
    int ans = 1;
    int prev = v[N-1].first;
    
    for(int i=N-2; i>=0; i--){
        if(v[i].second <= prev){
            prev = v[i].first;
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}