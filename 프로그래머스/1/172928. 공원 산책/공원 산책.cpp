#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    char map[50][50];
    int sx=0, sy=0;
    
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].length(); j++){
            map[i][j] = park[i][j];
            if(park[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        char dir = routes[i][0];
        int dis = routes[i][2] - '0';
        
        int nx = sx;
        int ny = sy;
        
        bool flag = false;
        
        for(int j=0; j<dis; j++){
            if(dir == 'E'){
                ny += 1;
            }
            else if(dir == 'W'){
                ny -= 1;
            }
            else if(dir == 'N'){
                nx -= 1;
            }
            else if(dir == 'S'){
                nx += 1;
            }    
            
            if(nx < 0 || nx >= park.size() || ny < 0 || ny >= park[0].length()){
                flag = true;
                break;
            }
            if(map[nx][ny] == 'X'){
                flag = true;
                break;   
            }
        }    
        if(!flag){
            sx = nx;
            sy = ny;   
        }
        flag = false;
    }
    
    answer.push_back(sx);
    answer.push_back(sy);
    
    return answer;
}







