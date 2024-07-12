#include <iostream>
using namespace std;

int N, M;
int selected[8];
// int visted[8];

void perm(int tgtIdx, int start){
    if(tgtIdx == M){
        for(int i=0; i<M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=start; i<=N; i++){
        selected[tgtIdx] = i;
        perm(tgtIdx+1, i+1);
    }
}

int main(){
    cin >> N >> M;

    perm(0, 1);

    return 0;
}