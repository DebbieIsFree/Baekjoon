#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> v;

    int mx = 0, my = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        mx = max(mx, x);
        my = max(my, y);
    }

    vector<int> ans;

    for (int i = 0; i <= my; i++) {
        for (int j = 0; j <= mx; j++) {
            int m = 0;
            for (int k = 0; k < N; k++) {
                int tmp = abs(v[k].first - j) + abs(v[k].second - i);
                if (m < tmp) {
                    m = tmp;
                }
            }
            ans.push_back(m);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0];

    return 0;
}
