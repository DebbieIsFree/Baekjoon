#include <iostream>
using namespace std;

// 최소 개수
int limit[4];
int cnt[4];
int ans = 0;

// S = 7, P = 3
// idx 0 ~ 6
// 1st) 0,1,2
// 2nd) 1,2,3
// 3rd) 2,3,4
// ..
// last)4,5,6

int main(){
    int S, P;   cin >> S >> P;
    string str; cin >> str;
    
    for(int i=0; i<4; i++){
        cin >> limit[i];
    }
    
    for(int i=0; i<P; i++){
        if(str[i] == 'A')  cnt[0]++;
        else if(str[i] == 'C') cnt[1]++;
        else if(str[i] == 'G') cnt[2]++;
        else if(str[i] == 'T') cnt[3]++;
    }
    if(cnt[0] >= limit[0] && cnt[1] >= limit[1] && 
        cnt[2] >= limit[2] && cnt[3] >= limit[3])
            ans++;
        
    for(int i=P; i<str.length(); i++){
        if(str[i-P] == 'A')  cnt[0]--;
        else if(str[i-P] == 'C') cnt[1]--;
        else if(str[i-P] == 'G') cnt[2]--;
        else if(str[i-P] == 'T') cnt[3]--;
        
        if(str[i] == 'A')  cnt[0]++;
        else if(str[i] == 'C') cnt[1]++;
        else if(str[i] == 'G') cnt[2]++;
        else if(str[i] == 'T') cnt[3]++;
        
        if(cnt[0] >= limit[0] && cnt[1] >= limit[1] && 
        cnt[2] >= limit[2] && cnt[3] >= limit[3])
            ans++;
    }
    
    cout << ans;

    return 0;
}
