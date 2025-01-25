/*
Author: passa
Subject: Breadth First Search
Language: C++ 
*/

#include <bits/stdc++.h>
using namespace std;

#define MXN 100100

int n,m,u,v;
int visited[MXN];
vector<int> g[MXN];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    q.push(1);
    while (!q.empty()) {
        u = q.front();
        cout << u << endl;
        visited[u] = true;
        q.pop();
        for (auto v: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}