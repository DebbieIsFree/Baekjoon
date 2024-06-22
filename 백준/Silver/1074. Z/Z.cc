#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int ans = 0;

// Z
int dr[] = {0, 0, 1, 1};
int dc[] = {0, 1, 0, 1};


void func(int row, int col, int len){
    if(len == 2){
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr == r && nc == c){
                cout << ans;
                break;
            }
            ans++;
        }
        return;
    }
    
    int nlen = len / 2;
    
    if((row <= r && r < row+len) && (col <= c && c < col+len)){
        func(row, col, nlen);
        func(row, col + nlen, nlen);
        func(row + nlen, col, nlen);
        func(row + nlen, col+nlen, nlen);
    }else{
        ans += len*len;
        return;
    }
}

int main(){
    cin >> N >> r >> c;
    
    int len = pow(2, N);
    
    func(0, 0, len);
    
    return 0;
}