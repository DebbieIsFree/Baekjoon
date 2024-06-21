#include <string>
#include <set>
using namespace std;

// U, D, L, R
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

// set<pair<pair<int, int>, pair<int, int>>> s; 
set<string> s;

int solution(string dirs) {
    int answer = 0;
    
    int cr = 0;
    int cc = 0;
    
    for(int i=0; i<dirs.length(); i++){
        int nr = cr;
        int nc = cc;
        
        if(dirs[i] == 'U'){
            nr += dr[0];
            nc += dc[0];
        }else if(dirs[i] == 'D'){
            nr += dr[1];
            nc += dc[1];
        }else if(dirs[i] == 'L'){
            nr += dr[2];
            nc += dc[2];
        }else if(dirs[i] == 'R'){
            nr += dr[3];
            nc += dc[3];
        }
        
        if(nr < -5 || nr > 5 || nc < -5 || nc > 5)
            continue;
        
        string route1 = "";
        route1 += to_string(cr) + to_string(cc);
        route1 += to_string(nr) + to_string(nc);
        
        string route2 = "";
        route2 += to_string(nr) + to_string(nc);
        route2 += to_string(cr) + to_string(cc);
        
        // if(s.find({{cr, cc}, {nr, nc}}) == s.end()){
        //     s.insert({{cr, cc}, {nr, nc}});
        //     answer++;   
        // }
        if(s.find(route1) == s.end() && s.find(route2) == s.end()){
            s.insert(route1);
            s.insert(route2);
            answer++;
        } 
        cr = nr;
        cc = nc;
    }
    
    return answer;
}