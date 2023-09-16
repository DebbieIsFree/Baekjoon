#include <string>
#include <vector>
#include <map>
using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) { 

    map<string, int> m1;
    map<int, string> m2;
    
    for(int i=0; i<players.size(); i++){
        m1.insert({players[i], i+1});
        m2.insert({i+1, players[i]});
    }
    
    for(int i=0; i<callings.size(); i++){
        string name = callings[i];   // kai
        int rank = m1[name];        // 4
        string prev_name = m2[rank-1];  // poe
        
        m1[name] -= 1;  // kai, 3
        m1[prev_name] += 1; // poe, 4
        m2[rank] = prev_name;  // 4, poe
        m2[rank-1] = name;  // 3, kai
    }
    
    vector<string> answer;
    
    for(int i=1; i<=players.size(); i++){
        answer.push_back(m2[i]);
    }
    
    return answer;
}




    