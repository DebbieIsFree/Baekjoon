#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int len = board.size();
    
    vector<stack<int>> v;
      
    v.resize(len);
    
    for(int i=len-1; i>=0; i--){
        for(int j=0; j<len; j++){
            v[j].push(board[i][j]);
        }
    }
    
    // for(int i=0; i<len; i++){
    //     for(int j=0; j<len; j++){
    //         cout << v[j].top();
    //         v[j].pop();
    //     }
    //     cout << endl;
    // }
    
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(v[j].top() == 0)
                v[j].pop();
        }
    }
    
    // for(int i=0; i<len; i++){
    //     while(!v[i].empty()){
    //         cout << v[i].top();
    //         v[i].pop();
    //     }
            
    //     cout << endl;
    // }
    
    stack<int> st;
    
    for(int i=0; i<moves.size(); i++){
        int col = moves[i] - 1;
        
        if(v[col].empty()){
            continue;
        }
        else if(st.empty()){
            st.push(v[col].top());
            v[col].pop();
        }
        else if(!v[col].empty() && st.top() == v[col].top()){
            // cout << endl << st.top() << " " << v[col].top();
            st.pop();
            v[col].pop();
            answer += 2;
        }
        else {
            st.push(v[col].top());
            v[col].pop();
        }
    }

    
    return answer;
}

