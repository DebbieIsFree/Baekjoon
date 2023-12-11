#include <iostream>
#include <stack>
using namespace std;

int main(){
    
    string str; cin >> str;
    stack<char> st;
    int res = 0;
    
    for(int i=0; i<str.length(); i++){
        if(str[i] == 'K' && st.empty()){
            st.push('K');
            res++;
        }
        
        if(st.empty())
            continue;
        
        if(st.top() == 'K' && str[i] == 'O'){
            st.push('O');
            res++;
        }
        else if(st.top() == 'O' && str[i] == 'R'){
            st.push('R');
            res++;
        }
        else if(st.top() == 'R' && str[i] == 'E'){
            st.push('E');
            res++;
        }
        else if(st.top() == 'E' && str[i] == 'A'){
            st.push('A');
            res++;
            while(!st.empty()){
                st.pop();
            }
        }
    }
    
    cout << res;
    
    
    return 0;
}
