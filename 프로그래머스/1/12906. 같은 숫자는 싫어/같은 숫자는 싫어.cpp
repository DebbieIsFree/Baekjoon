#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    stack<int> st;
    
    for(int i=0; i<arr.size(); i++){
        if(st.empty()){
            st.push(arr[i]);
        }
        else if(st.top() == arr[i]){
            st.pop();
            st.push(arr[i]);
        }
        else {
            st.push(arr[i]);
        }
    }
    
    int len = st.size();
    
    answer.resize(len, 0);
    
    for(int i=len-1; i>=0; i--){
        answer[i] = st.top();
        st.pop();
    }
    
    return answer;
}