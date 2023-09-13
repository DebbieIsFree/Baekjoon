#include <iostream>

using namespace std;

bool visited[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
   int N = 4;
   int res = 0;
   int sub = 0;
   
   while(N--){
       int x1, y1, x2, y2;
       cin >> x1 >> y1 >> x2 >> y2;
       
       for(int i=x1; i<x2; i++){
           for(int j=y1; j<y2; j++){
               if(visited[i][j]){
                   continue;
               }
               visited[i][j] = true;
               res += 1;
           }
       }
   }
   
   cout << res;
  
  
    return 0;
}
