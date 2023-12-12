#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int T;  cin >> T;
    
    while(T--){
        int t;  cin >> t;
        int m = 0;
        
        for(int i=1; i<t; i++){
            int late = i*i;
            if(i + late <= t){
                m = i;
            }
        }
        
        cout << m << "\n";
    }
    
    
    
    return 0;
}
