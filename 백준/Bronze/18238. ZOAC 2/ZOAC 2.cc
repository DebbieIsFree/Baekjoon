#include <iostream>
#include <math.h>

using namespace std;

int main(){
    string str;   cin >> str;
    
    char c = 'A';
    
    int res = 0;

    for(int i=0; i<str.length(); i++){
        int v1 = abs(c - str[i]);
        int v2 = 26 - abs(c - str[i]);
        
        c = str[i];
    
        if(v1 < v2)
            res += v1;
        else
            res += v2;
    }
    
    cout << res;
    

    return 0;
}
