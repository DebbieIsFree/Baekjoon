#include <iostream>
using namespace std;

int N, M;
int selected[8];

void comb(int tgtIdx, int startIdx){
    if(tgtIdx == M){
        for(int i=0; i<M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=startIdx; i<=N; i++){
        selected[tgtIdx] = i;
        comb(tgtIdx+1, i);
    }
}

int main(){
    cin >> N >> M;
    
    comb(0, 1);

    return 0;
}