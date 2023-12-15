#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int K;
int num;

vector<vector<int>> tree(10);
int arr[1024];

void recursion(int s, int e, int depth){
    if(s > e)
        return;
    if(s == e){
        tree[depth].push_back(arr[s]);
        return;
    }
    
    int mid = (s+e)/2;
    
    if(mid < 0 || mid >= num)
        return;
    
    tree[depth].push_back(arr[mid]);
    
    recursion(s, mid-1, depth+1);
    recursion(mid+1, e, depth+1);
}

int main(){
    
    cin >> K;
    num = pow(2, K) - 1;
    
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }
    
    recursion(0, num-1, 0);
    
    for(int i=0; i<K; i++){
        for(int j=0; j<tree[i].size(); j++){
            cout << tree[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
