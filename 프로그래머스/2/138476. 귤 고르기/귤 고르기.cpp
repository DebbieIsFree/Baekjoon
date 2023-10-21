#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<int> v(10000001);
    int len = tangerine.size();

    
    
    for(int i=0; i<tangerine.size(); i++){
        int idx = tangerine[i];
        v[idx] += 1;
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    int cnt = 0;
    int i = 0;
    int res = 0;
    
    while(cnt < k){
        if(i >= len)
            break;
        
        int n = v[i];
        if(cnt + n <= k){
            cnt += n;
            i++;
            res++;
        }
        else {
            int tmp = k - cnt;
            if(n >= tmp){
                cnt += tmp;
                res++;
                break;
            }
            else {
                cnt += n;
                res++;
                i++;
            }
        }
    }
    
    answer = res;
    
    
    return answer;
}

