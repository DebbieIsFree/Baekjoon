#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// vector<int> xarr;
// vector<int> yarr;

int main(){

    int T; cin >> T;
    cin.ignore();

    while(T--){
        string str;
        getline(cin, str);
        
        vector<int> xarr;
        vector<int> yarr;

        
        xarr.push_back(0);
        yarr.push_back(0);

        int x = 0, y = 0;
        int d = 90;
        
        int size = str.length();
        
        for(int i=0; i<size; i++){
            char c = str[i];
            
            if(c == 'F'){
                if(d == 0){
                    x++;
                }
                else if(d == 90){
                    y++;
                }
                else if(d == 180){
                    x--;
                }
                else if(d == 270){
                    y--;
                }
            }
            else if(c == 'B'){
                if(d == 0){
                    x--;
                }
                else if(d == 90){
                    y--;
                }
                else if(d == 180){
                    x++;
                }
                else if(d == 270){
                    y++;
                }
            }
            else if(c == 'L'){
                if(d  == 270){
                    d = 0;
                }else{
                    d += 90;

                }
            }
            else if(c == 'R'){
                if(d == 0){
                    d = 270;
                }else{
                    d -= 90;
                }
            }
            xarr.push_back(x);
            yarr.push_back(y);
        }

        sort(xarr.begin(), xarr.end());
        sort(yarr.begin(), yarr.end());
        
        int xidx = xarr.size();
        int yidx = yarr.size();
        
        // cout << endl << xarr[0] << ", " << xarr[xidx-1] << endl;
        // cout << endl << yarr[0] << ", " << yarr[yidx-1] << endl;
    
        int garo = abs(xarr[xidx-1] - xarr[0]);
        int sero = abs(yarr[yidx-1] - yarr[0]);

        
        cout << garo * sero << "\n";   
    }
    
    
    return 0;
}

