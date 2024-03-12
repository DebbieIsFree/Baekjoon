#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
string selected[3];
vector<string> v;
int ans = 1e9;

void calc(){
    int tmp = 0;
    
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            if(selected[i][j] != selected[i+1][j]){
                tmp++;    
            }
        }
    }
    for(int j=0; j<4; j++){
        if(selected[2][j] != selected[0][j])
            tmp++;    
    }
    
    ans = min(ans, tmp);
}

void comb (int srcIdx, int tgtIdx){
    if (tgtIdx == 3){
        calc();
	    return;
    }
    if (srcIdx == N)
	    return;
	    
    selected[tgtIdx] = v[srcIdx];
    comb(srcIdx+1, tgtIdx+1);
    comb(srcIdx+1, tgtIdx);
}

int main (){
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    
    cin >> T;

    while (T--){
        cin >> N;
        
        v.clear ();
	    
	    for (int i = 0; i < N; i++){
	        string str;
		    cin >> str;
		    v.push_back (str);
	    }
        
        ans = 1e9;
        
        sort(v.begin(), v.end());
        
        if(N > 32)
            ans = 0;
	    else
	        comb (0, 0);
	    
	    cout << ans << "\n";
    }
    
    return 0;
}
