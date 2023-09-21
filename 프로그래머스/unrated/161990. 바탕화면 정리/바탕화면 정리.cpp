#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int x_max = 0, x_min = 0;
    int y_max = 0, y_min = 0;
    
    bool flag[2] = {false, false};
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].length(); j++){
            if(!flag[0]){
                if(wallpaper[i][j] == '#'){
                    x_min = i;
                    x_max = i;
                    flag[0] = true;
                }
            }                 
            else if(flag[0]){
                if(wallpaper[i][j] == '#'){
                    if(x_max < i){
                        x_max = i;
                    }
                }
            }
            if(!flag[1]){
                if(wallpaper[i][j] == '#'){
                    y_min = j;
                    y_max = j;
                    flag[1] = true;
                }
            }                 
            else if(flag[1]){
                if(wallpaper[i][j] == '#'){
                    if(j < y_min){
                        y_min = j;
                    }
                    if(j > y_max){
                        y_max = j;
                    }
                }
            }
        }
    }
    
    answer.push_back(x_min);
    answer.push_back(y_min);
    answer.push_back(x_max+1);
    answer.push_back(y_max+1);
    
    return answer;
}