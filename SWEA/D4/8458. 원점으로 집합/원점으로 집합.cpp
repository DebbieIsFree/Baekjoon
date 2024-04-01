#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    
    for(int t=1; t<=T; t++){
        int n;  cin >> n;
        
        vector<long long> v;
        
        for(int i=0; i<n; i++){
            long long x, y;
            cin >> x >> y;
            long long tmp = abs(x) + abs(y);
            v.push_back(tmp);
        }
        
        int f = v[0] % 2;
        bool FLAG = false;
        for(int i=1; i<n; i++){
            if(v[i] % 2 != f){
                FLAG = true;
            }
        }
        if(FLAG){
            cout << "#" << t << " -1\n";
            continue;
        }    
        
        sort(v.begin(), v.end(), greater<long long>());
        
        long long m = v[0];
        
        long long i = 0;
        long long sum = 0;
        while(true){
            sum += i;
            if(sum >= m && (sum-m) % 2 == 0){
                break;
            }
            i++;
        }
        
        cout << "#" << t << " " << i << "\n";
    }

    return 0;
}

