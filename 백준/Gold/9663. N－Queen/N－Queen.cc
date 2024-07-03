#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int ans = 0;
int rowCh[15];

void nqueen(int row, int col, int cnt, int rowCheck[15]){
    if(cnt == N){
        ans++;
        return;
    }
    
    int copyRowCheck[15];

    for(int i=0; i<N; i++){
        copyRowCheck[i] = rowCheck[i];
    }
    
    for(int i=0; i<N; i++){            // col
        bool flag = false;
        int c = i;
        
        for(int j=0; j<=row; j++){     // row
            if(i == copyRowCheck[j]){
                flag = true;
                break;
            }
                
            if(abs(row+1-j) == abs(i-copyRowCheck[j])){
                flag = true;
                break;
            }
        }    
        if(!flag){
            copyRowCheck[row+1] = c;
            nqueen(row+1, c, cnt+1, copyRowCheck);   
        }
    }   
}

int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        fill_n(rowCh, 15, -1);
        rowCh[0] = i;
        nqueen(0, i, 1, rowCh);
    }
    
    cout << ans;

    return 0;
}