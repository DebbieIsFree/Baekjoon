#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int arr[5] = {0,};
    
    string str = "";
    for(int i=0; i<5; i++){
        cin >> arr[i];
        str += to_string(arr[i]);
    }
    
    while(str != "12345"){
        string tmp = "";
        for(int i=0; i<4; i++){
            if(arr[i] > arr[i+1]){
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                
                for(int j=0; j<5; j++){
                    cout << arr[j] << " ";
                }
                cout << endl;
            }
            tmp += to_string(arr[i]);
        }    
        tmp += to_string(arr[4]);
        str = tmp;
    }


    return 0;
}
