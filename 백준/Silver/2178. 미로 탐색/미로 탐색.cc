#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[100][100];
bool visited[100][100];
int cnt[100][100];
queue<pair<int,int>> q;

int dm[4] = { -1, +1, 0, 0 };
int dn[4] = { 0, 0, -1, +1 };

void BFS(int n, int m);

int N, M;
//int cnt = 0;

int main() {
	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	BFS(0, 0);

	cout << cnt[N-1][M-1];

	return 0;
}

void BFS(int n, int m) {
	//cnt++;
	cnt[n][m] += 1;
	
	visited[n][m] = true;
	q.push({ n, m });

	while (!q.empty()) {
		int nn = q.front().first;
		int nm = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nextn = nn + dn[k];
			int nextm = nm + dm[k];
			if (nextm < 0 || nextm >= M || nextn < 0 || nextn >= N)
				continue;
			if (!visited[nextn][nextm] && arr[nextn][nextm]) {
				q.push({ nextn, nextm });
				visited[nextn][nextm] = true;
				//cnt++;
				cnt[nextn][nextm] = cnt[nn][nm] + 1;
			}
		}
	}
}