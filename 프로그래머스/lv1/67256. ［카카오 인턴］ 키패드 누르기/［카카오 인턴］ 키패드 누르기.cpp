#include <string>
#include <vector>
#include <math.h>

using namespace std;


string solution(vector<int> numbers, string hand) {    
    string answer = "";
    
    vector<pair<int ,int>> v;
    v.push_back({4,2});
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            v.push_back({i, j});
        }
    }
    
    int lx = 4, ly = 1;
    int rx = 4, ry = 3;
    int lv = 10, rv = 12;
    
    for(int i=0; i<numbers.size(); i++){
        int num = numbers[i];
        if(num == 1 || num == 4 || num == 7){
            answer += "L";
            lx = v[num].first;
            ly = v[num].second;
            lv = num;
        }
        else if(num == 3 || num == 6 || num == 9){
            answer += "R";
            rx = v[num].first;
            ry = v[num].second;
            rv = num;
        }else{
            int ltmp = abs(v[num].first - lx) + abs(v[num].second - ly);
            int rtmp = abs(v[num].first - rx) + abs(v[num].second - ry);
            
            if(ltmp == rtmp){
                if(hand == "right"){
                    rx = v[num].first;
                    ry = v[num].second;
                    rv = num;
                    answer += "R";
                }else{
                    lx = v[num].first;
                    ly = v[num].second;
                    lv = num;
                    answer += "L";
                }
            }
            else if(ltmp < rtmp){
                lx = v[num].first;
                ly = v[num].second;
                lv = num;
                answer += "L";
            }else{
                rx = v[num].first;
                ry = v[num].second;
                rv = num;
                answer += "R";
            }
        }
    }
    
    return answer;
}