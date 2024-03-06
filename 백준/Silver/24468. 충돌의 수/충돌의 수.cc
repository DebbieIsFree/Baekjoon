#include <iostream>
#include <vector>
using namespace std;

int main(){
    int L, N, T, ans;
    cin >> L >> N >> T;
    
    // 좌표, 방향
    vector<pair<int,char>> v;
    
    for(int i=0; i<N; i++){
        int idx;
        char dir;   // L or R
        cin >> idx >> dir;
        v.push_back({idx, dir});
    }

    for(int t=1; t<=T; t++){
        for(int i=0; i<N; i++){
            if(v[i].second == 'L')
                v[i].first -= 1;
            else 
                v[i].first += 1;
        }
        
        int count[10001] = {0,};
            
        for(int i=0; i<N; i++){
            int idx = v[i].first;
            count[idx] += 1;
        }
        
        int tmp = 0;
        
        for(int i=0; i<N; i++){
            // 벽이랑 충돌할 때 (좌표가 0 or L)
            if(v[i].first == 0){
                v[i].second = 'R';
                // ans++;
            }
            else if(v[i].first == L){
                v[i].second = 'L';
                // ans++;
            }
            // 공끼리 충돌할 때 
            else if(count[v[i].first] >= 2){
                if(v[i].second == 'L')
                    v[i].second = 'R';
                else 
                    v[i].second = 'L';
                tmp++;
            }
        }
        ans += (tmp/2);
    }
    
    cout << ans;

    return 0;
}
