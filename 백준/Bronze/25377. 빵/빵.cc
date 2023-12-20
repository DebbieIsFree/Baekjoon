#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    vector<pair<int, int>> v;
    
    while(N--){
        int go, bread;
        cin >> go >> bread;
        v.push_back({go, bread});
    }
    
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    
    int res = 99999;
    
    for(int i=0; i<v.size(); i++){
        if(v[i].second >= v[i].first){
            if(res > v[i].second){
                res = v[i].second;
            }
        }
    }
    
    if(res != 99999)
        cout << res;
    else 
        cout << "-1";
    
    return 0;
}
