#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int arr[21][21];
int selected[10];
bool check[21]; 
int ans = 987654321;

int calc(int select[10]){
    int s1 = 0, s2 = 0;
    fill_n(check, 21, false);
    
    for(int i=0; i<N/2; i++){
        int a = select[i];
        check[a] = true;
        
        for(int j=0; j<N/2; j++){
            int b = select[j];
            check[b] = true;
            
            if(a == b)
                continue;
            
            s1 += arr[a][b];
            s1 += arr[b][a];
        }
    }
    
    
    for(int i=1; i<=N; i++){
        if(check[i])
            continue;
        
        for(int j=1; j<=N; j++){
            if(check[j])
                continue;
            
            if(i == j)
                continue;
            
            s2 += arr[i][j];
            s2 += arr[j][i];
        }
    }
    
    s1 /= 2;
    s2 /= 2;
    
    return abs(s1-s2);
}


void comb(int tgtIdx, int startIdx){
    if(tgtIdx == N/2){
        int res = calc(selected);
        ans = min(ans, res);
        return;
    }
    
    for(int i=startIdx; i<=N; i++){
        selected[tgtIdx] = i;
        comb(tgtIdx+1, i+1);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    
    comb(0, 1);
    
    cout << ans;

    return 0;
}