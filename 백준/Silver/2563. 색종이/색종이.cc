#include <iostream>
using namespace std;

// a에서 10개 : a <= i < a+10 임을 유의!!!

bool check[101][101];

int main(){
    int N;  cin >> N;
    int tmp = N;
    int cnt = 0;
    
    while(N--){
        int hor, ver;
        cin >> hor >> ver;
        
        for(int i=hor; i<hor+10; i++){
            for(int j=ver; j<ver+10; j++){
                if(check[i][j]){
                    cnt++;
                    
                }else{
                    check[i][j] = true;
                }
            }
        } 
    }
    
    int width = 10 * 10 * tmp;
    
    cout << width - cnt;

    return 0;
}
