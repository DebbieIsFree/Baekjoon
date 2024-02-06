#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 987654321;
priority_queue<pair<int,int>> pq;
vector<pair<int, int>> adj[20001];

vector<int> dijkstra(int start, int v, int e);

int main() {
	int V, E, K;
	cin >> V >> E;
	cin >> K;

	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	vector<int> dist = dijkstra(K, V, E);
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] < INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
}


vector<int> dijkstra(int start, int v, int e) {
	vector<int> distance(v+1, INF);
	distance[start] = 0;

	pq.push({0, start});

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (distance[now] < cost)
			continue;

		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int nextCost = adj[now][i].second + cost;

			if (nextCost < distance[next]) {
				distance[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}
	return distance;
}

