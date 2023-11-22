#include <iostream>

using namespace std;

char arr[100][100];

int main(){
    
    int H, W;
    cin >> H >> W;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr[i][j];
        }
    }


    for(int i=0; i<H; i++){
        int cloud = -1;
        for(int j=0; j<W; j++){
            if(arr[i][j] == 'c'){
                cloud = j;
                cout << "0 ";
            }
            else if(cloud == -1 || j < cloud){
                cout << "-1 ";
            }
            else if(j > cloud){
                cout << j - cloud << " ";
            }
        }
        cout << "\n";
    }    

    return 0;
}


