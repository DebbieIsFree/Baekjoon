#include <string>
#include <vector>
#include <stack>
using namespace std;

string func(int n, int len){
    string str = "";
    stack<int> st;
    while(st.size() < len){
        int tmp = n % 2;
        st.push(tmp);
        n = n / 2;
    }
    
    while(!st.empty()){
        str += st.top();
        st.pop();
    }
      
    return str;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    char map[16][16];
    
    for(int i=0; i<n; i++){
        string str = func(arr1[i], n);
        for(int j=0; j<n; j++){
            if(str[j] == 1)
                map[i][j] = '#';
            else if(str[j] == 0)
                map[i][j] = ' ';
        }
    }
    
    for(int i=0; i<n; i++){
        string str = func(arr2[i], n);
        for(int j=0; j<n; j++){
            if(str[j] == 1)
                map[i][j] = '#';
            else if(map[i][j] == ' ' && str[j] == 0)
                map[i][j] = ' ';
            else if(map[i][j] == '#' && str[j] == 0)
                map[i][j] = '#';
        }
    }
    
    for(int i=0; i<n; i++){
        string s = "";
        for(int j=0; j<n; j++){
            s += map[i][j];
        }
        answer.push_back(s);
    }
    
    
    return answer;
}












