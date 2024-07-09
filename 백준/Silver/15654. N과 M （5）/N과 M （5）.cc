#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int selected[8];
bool isSelected[9];

void perm(int tgtIdx, int startIdx){
    if(tgtIdx == M){
        for(int i=0; i<M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<N; i++){
        if(isSelected[i])
            continue;
        
        selected[tgtIdx] = v[i];
        isSelected[i] = true;
        perm(tgtIdx+1, i);
        isSelected[i] = false;
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        int n;  cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    
    perm(0, 0);

    return 0;
}