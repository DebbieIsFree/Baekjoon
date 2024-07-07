#include <string>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> answer;
stack<pair<int,int>> st;     // {price, index}
int result[100001];

vector<int> solution(vector<int> prices) {
    N = prices.size();
    
    for(int i=0; i<N; i++){
        if(st.empty())
            st.push({prices[i], i+1});
        else{
            if(st.top().first <= prices[i]){
                st.push({prices[i], i+1});
            }else{
                while(!st.empty() && st.top().first > prices[i]){
                    int idx = st.top().second;
                    result[idx] = (i+1) - idx;
                    st.pop();
                }
                st.push({prices[i], i+1});
            }
        }
    }
    
    while(!st.empty()){
        int idx = st.top().second;
        result[idx] = N-idx;
        st.pop();
    }
    
    for(int i=1; i<=N; i++){
        answer.push_back(result[i]);
    }
    
    return answer;
}  