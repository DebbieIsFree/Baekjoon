#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    
    map<string ,int> m;
    
    for(int i=0; i<players.size(); i++){
        m[players[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++){
        string name = callings[i];
        int rank = m[name];  // JJW, 3 ---> 2
        m[name] -= 1;    // 
        
        string prev_name = players[rank-1];    
        players[rank-1] = name;
        players[rank] = prev_name;
        m[prev_name] += 1;   // ?, 3
    }
    
    vector<string> answer;
    
    for(int i=0; i<players.size(); i++){
        answer.push_back(players[i]);
    }
    
    return answer;
}