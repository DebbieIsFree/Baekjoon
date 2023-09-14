#include <iostream>
#include <string>
using namespace std;

// 알파벳 : 열
// 숫자 : 행

void move(int &x, int &y, string str){
    int fx = x;
    int fy = y;
    
    if(str == "R"){
        y++;
    }
    else if(str == "L"){
        y--;
    }
    else if(str == "T"){
        x++;
    }
    else if(str == "B"){
        x--;
    }
    else if(str == "RT"){
        y++;
        x++;
    }
    else if(str == "RB"){
        y++;
        x--;
    }
    else if(str =="LT"){
        y--;
        x++;
    }
    else if(str == "LB"){
        y--;
        x--;
    }
    
    if(x < 1 || x > 8 || y < 0 || y >= 8){
        x = fx;
        y = fy;
    }
}

int main(){
    string K, S;
    int N;
    
    cin >> K >> S >> N;
    cin.ignore();
    
    int ky = K[0] - '0' - 17 ;    // 열
    int kx = K[1] - '0';          // 행   
    
    int sy = S[0] - '0' - 17;
    int sx = S[1] - '0';
    
    // cout << endl;
    // cout << ky << endl;
    // cout << kx << endl;
    
    while(N--){
        string str; cin >> str;
        
        int bkx = kx, bky = ky;
        int bsx = sx, bsy = sy;
        
        move(kx, ky, str);
        
        if(kx == sx && ky == sy){
            move(sx, sy, str);
            
            if(sx == bsx && sy == bsy){
                kx = bkx;
                ky = bky;
            }
        }
    }
    
    
    char cky = ky + 65;
    char csy = sy + 65;
    
    cout << cky << kx << "\n" << csy << sx;
    

    return 0;
}


