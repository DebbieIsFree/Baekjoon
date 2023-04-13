#include <iostream>
#include <stack>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    
    int k;  cin >> k;
    int ans = 0;
    
    for(int i=0; i<k; i++){
        int n;  cin >> n;
        if(n == 0 && !st.empty()){
            ans -= st.top();
            st.pop();
        }
        if(n > 0){
            st.push(n);
            ans += n;
        }
    }
    
    cout << ans;
 
    
    return 0;
}