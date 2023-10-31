#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    int arr1_row = arr1.size();
    int arr1_col = arr1[0].size();
    int arr2_col = arr2[0].size();

    vector<vector<int>> answer(arr1_row, vector<int>(arr2_col, 0));

    for(int i = 0; i < arr1_row; i++) {
        for(int j = 0; j < arr2_col; j++) {
            for(int k = 0; k < arr1_col; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}


