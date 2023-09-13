#include <iostream>
#include <algorithm>

using namespace std;

int weight[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  cin >> N;

    for(int i=0; i<N; i++){
        cin >> weight[i];
    }  
  
    if(prev_permutation(weight, weight+N)){
        for(int i=0; i<N; i++){
            cout << weight[i] << " ";
        }
    }else{
        cout << "-1";
    }
  
  
    return 0;
}
