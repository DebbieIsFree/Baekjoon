#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);  cin.tie(nullptr);
   
    while(true){
        stack<char> st;
        
        string str; getline(cin, str);
        
        if(str == "."){
            return 0;
        }
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '('){
                st.push('(');
            }
            else if(str[i] == '['){
                st.push('[');
            }
            else if(str[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push('%');
                    break;
                }
            }
            else if(str[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    st.push('%');
                    break;
                }
            }
        }
        
        if(st.empty()){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
   
    return 0;
}
