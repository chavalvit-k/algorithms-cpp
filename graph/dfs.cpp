/*
Author: passa
Subject: Depth First Search
Language: C++ 
*/

#include <bits/stdc++.h>
using namespace std;

#define MXN 100100

int n,m,u,v;
int visited[MXN];
vector<int> g[MXN];
stack<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    s.push(1);
    while (!s.empty()) {
        u = s.top();
        cout << u << endl;
        visited[u] = true;
        s.pop();
        for (auto v: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    
    return 0;
}