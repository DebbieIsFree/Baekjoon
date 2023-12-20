#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        v[i] = i + 1;
    }
    
    while(v.size() > 1){
        vector<int> tmp;
        for(int i=0; i<v.size(); i++){
            if((i+1) % 2 == 0){
                tmp.push_back(v[i]);
            }
        }
        v.resize(tmp.size());
        
        for(int i=0; i<tmp.size(); i++){
            v[i] = tmp[i];
        }
    }

    cout << v[0];

    return 0;
}
