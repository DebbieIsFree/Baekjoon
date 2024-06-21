#include <iostream>
using namespace std;

int N;
int arr[128][128];
int blue = 0;
int white = 0;

void func(int row, int col, int size){
    if(size == 1){
        if(arr[row][col] == 0)
            white++;
        else
            blue++;
        return;
    }
    
    bool flag = false;
    
    for(int i=row; i<row+size; i++){
        for(int j=col; j<col+size; j++){
            if(arr[row][col] != arr[i][j]){
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        if(arr[row][col] == 0)
            white++;
        else
            blue++;
    }else{
        int sz = size / 2;
        func(row, col, sz);
        func(row+sz, col, sz);
        func(row, col+sz, sz);
        func(row+sz, col+sz, sz);
    }
}

int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    func(0, 0, N);
    
    cout << white << "\n" << blue;

    return 0;
}