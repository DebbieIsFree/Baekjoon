#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    
    int N;  cin >> N;
    
    vector<int> a(N);
    vector<int> b(N);
    
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    
    for(int i=0; i<N; i++){
        cin >> b[i];
    }
    
    int sum = 0;
    
    for(int i=0; i<N; i++){
        sum += abs(a[i]-b[i]);
    }
    
    
    cout << sum / 2;
    
    return 0;
}


