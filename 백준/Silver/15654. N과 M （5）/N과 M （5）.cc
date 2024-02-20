#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> input;
int selected[8];

void func(int cnt, int mask){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << selected[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<N; i++){
        if((mask & 1 << i) != 0)         
            continue;
        selected[cnt] = input[i];
        func(cnt+1, mask | 1 << i);
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int n; cin >> n;
        input.push_back(n);
    }
    
    sort(input.begin(), input.end());
    
    func(0, 0);
    
    return 0;
}
