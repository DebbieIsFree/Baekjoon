#include <iostream>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;  cin >> N;
    string str;     cin >> str;
    
    int res = 0;
    int i = 0;
    
    while(i <=N-4){
        if(str[i] == 'p' && str[i+1]=='P' && str[i+2] == 'A' && str[i+3] == 'p'){
            res++;
            i += 4;
        }
        else{
            i++;
        }
    }
    
    cout << res;
    
    return 0;
}
