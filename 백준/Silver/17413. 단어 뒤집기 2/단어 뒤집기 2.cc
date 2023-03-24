#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    stack<char> st;
    queue<char> q;

    bool flag = false;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') { 
            q.push('<');
            flag = true;
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
        else if (str[i] == '>') {
            q.push('>');
            flag = false;
            while (!q.empty()) {
                cout << q.front();
                q.pop();
            }
        }
        else if (flag) {
            q.push(str[i]);
        }
        else if (str[i] == ' ') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << ' ';
        }
        else {
            st.push(str[i]);
        }
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << ' ';


    return 0;
}