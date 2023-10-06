#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    int N;  cin >> N;
    
    vector<int> v;
    
    int arr[11];
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    // 2 1 1 0
    
    // 4 2 1 3
    
    for(int i=N-1; i>=0; i--){
        vector<int>::iterator iter = v.begin();
        
        for(int j=0; j<arr[i]; j++){
            iter++;
        }
        
        v.insert(iter, i+1);
    }
    
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    
    
    return 0;
}
