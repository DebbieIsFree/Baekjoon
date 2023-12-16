#include <iostream>
#include <vector>
using namespace std;

int N;
int result = 0;
bool visited[16];
int check[16];

void backtracking(int row) {
    if (row == N + 1) {
        result++;
        return;
    }

    for (int i = 1; i <= N; i++) {
        bool flag = false;
        for (int j = 1; j < row; j++) {
            if (check[j] == i || (j + check[j] == row + i) || (j - check[j] == row - i)) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            check[row] = i;
            backtracking(row + 1);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        check[1] = i;
        backtracking(2);
    }

    cout << result;

    return 0;
}
