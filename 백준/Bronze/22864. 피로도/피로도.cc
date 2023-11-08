#include <iostream>

using namespace std;

int main(){
    
    int work, output, rest, limit;
    cin >>  work >> output >> rest >> limit;
    
    int cur_limit = 0;
    int cur_output = 0;
    
    for(int i=0; i<24; i++){
        if(cur_limit + work <= limit){
            cur_limit += work;
            cur_output += output;
        }else{
            cur_limit -= rest;
            if(cur_limit < 0){
                cur_limit = 0;
            }
        }    
    }
    
    cout << cur_output;

    return 0;
}
