#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    
    int N;  cin >> N;
    
    // 값, 인덱스
    stack<pair<int, int>> st;
    
    for(int i=1; i<=N; i++){
        int n;  cin >> n;
        
        // 지금 넣으려는 탑보다 낮은 탑은 
        // 영원히 필요없으므로 제거한다
        while(!st.empty() && st.top().first <= n){
            st.pop();
        }
        if(st.empty())
            cout << "0 ";
        else
            cout << st.top().second << " ";  // 인덱스 출력      
        
        st.push({n, i});
    }

    return 0;
}

