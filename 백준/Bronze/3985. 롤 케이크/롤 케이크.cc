#include <iostream>

using namespace std;

int main(){
    
    int len;  cin >> len;
    int N;  cin >> N;
    
    int m = 0;
    int p = 0;
    int res = 0;
    int res_p = 9999;
    
    bool check[1001] = {0,};
    
    for(int k=1; k<=N; k++){
        int s, e;
        cin >> s >> e;
        
        if(m < e - s + 1){
            m = e - s + 1;
            p = k;
        }
        
        int tmp_cnt = 0;
        
        for(int i=0; i<e-s+1; i++){
            if(!check[s+i]){
                check[s+i] = true;
                tmp_cnt++;
            }
        }
        
        if(res < tmp_cnt){
            res = tmp_cnt;
            
            res_p = k;
        
        }
    }
    
    cout << p << "\n" << res_p;

    return 0;
}
