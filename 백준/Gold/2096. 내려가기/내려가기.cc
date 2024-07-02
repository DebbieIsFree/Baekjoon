#include <iostream>
#include <algorithm>
using namespace std;

int min1, min2, min3;
int max1, max2, max3;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;  cin >> N;

    int n1, n2, n3, tmp;
    
    for(int i=1; i<=N; i++){
        cin >> n1 >> n2 >> n3;
        
        if(i == 1){
            min1 = max1 = n1;
            min2 = max2 = n2;
            min3 = max3 = n3;
            continue;
        }
        
        tmp = min2;
        min2 = min(min(min1, min2), min3) + n2;
        min1 = min(min1, tmp) + n1;
        min3 = min(tmp, min3) + n3;
        
        tmp = max2;
        max2 = max(max(max1, max2), max3) + n2;
        max1 = max(max1, tmp) + n1;
        max3 = max(tmp, max3) + n3;
    }
    
    cout << max(max(max1, max2), max3) << " " << min(min(min1, min2), min3);

    return 0;
}