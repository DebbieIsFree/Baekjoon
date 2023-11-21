#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){ 
    
    int N, K;   cin >> N >> K;
    
    string str; cin >> str;
    
    int arr[20] = {0,};
    
    stringstream ss(str);
    string buffer;
    
    int idx = 0;
    while(getline(ss, buffer, ',')){
        arr[idx] = stoi(buffer);
        idx++;
    }
   
    for(int i=0; i<K; i++){
        for(int j=0; j<N-i-1; j++){
            arr[j] = arr[j+1] - arr[j];
        }
    }
    
    for(int i=0; i<N-K; i++){
        cout << arr[i];
        if(i != N-K-1)
            cout << ",";
    }
    
    return 0;
}
