#include <iostream>
#include <numeric>
using namespace std;

int arr[10];

int func(int start, int end){
    int s = 1;
    for(int i=start; i<=end; i++){
        s *= arr[i];
    }
    return s;
}

int main(){
    
    int N;  cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int m = 0;
    
    for(int i=0; i<N-3; i++){
        for(int j=i+1; j<N-2; j++){
            for(int k=j+1; k<N-1; k++){
                int sum = func(0, i) + func(i+1, j) + func(j+1, k) + func(k+1, N-1);
                
                if(m < sum)
                    m = sum;
            }
        }
    }
    
    cout << m;

    return 0;
}
