#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> garo;
vector<int> sero;

int solution(vector<vector<int>> input) {
    int answer = 0;
    
    for(int i=0; i<input.size(); i++){
        garo.push_back(input[i][0]);
        sero.push_back(input[i][1]);
    }
      
    int idx = 0;
    
    while(idx < input.size()){
        int gr = garo[idx];
        int sr = sero[idx];
            
        if(gr < sr){
            garo[idx] = sr;
            sero[idx] = gr;
        }
        
        idx++;
    }
    
    int garoMax = *max_element(garo.begin(), garo.end());
    int seroMax = *max_element(sero.begin(), sero.end());
    
    answer = garoMax * seroMax;
    
    return answer;
}