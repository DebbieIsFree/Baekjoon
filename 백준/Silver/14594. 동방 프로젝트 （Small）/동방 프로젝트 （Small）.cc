#include <iostream>

using namespace std;

bool check[101];
bool check2[101];

int main(){
    
    int N;  cin >> N;
    int M;  cin >> M;
    
    while(M--){
        int x, y;
        cin >> x >> y;
        
        for(int i=x; i<y; i++){
            check[i] = true;
        }
        
        for(int i=x; i<=y; i++){
            check2[i] = true;
        }
    }
    
    bool flag = false;
    int ans = 0;
    int tmp = 0;
    
    for(int i=1; i<=N-1; i++){
        if(check[i] == true && flag == false){
            flag = true;
            ans++;
        }
        else if(check[i] == false){
            flag = false;
        }
    }
    
    for(int i=1; i<=N; i++){
        if(!check2[i])
            tmp++;
    }
    
    cout << tmp+ans;

    return 0;
}
