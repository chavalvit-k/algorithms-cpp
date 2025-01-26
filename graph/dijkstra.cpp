/*
Author: passa
Subjuct: Shortest Path: Dijkstra's
Language: C++ 
*/

#include <bits/stdc++.h>
using namespace std;

#define MXN 100100

const long long INF = numeric_limits<long long>::max();

typedef pair<long long, int> P;

int n,m,u,v,w,d;
long long dist[MXN];
vector<P> g[MXN];
priority_queue<P, vector<P>, greater<P>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u}); 
    }

    for (int i = 1 ; i <= n ; i++) dist[i] = INF;

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        d = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto vv: g[u]) {
            v = vv.first;
            w = vv.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int u = 1 ; u <= n ; u++) cout << dist[u] << endl;

    return 0;
}