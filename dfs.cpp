#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
#define forn(i, j, n) for(int i = j; i < n; i++)
#define endl "\n"


void dfs (vvi& graph, vb& visited, int v) {

    cout << v << " ";
    visited[v] = true;

    for (auto adj : graph[v]) {
        if (!visited[adj])
            dfs(graph, visited, adj);
    }
}

void solve (vvi& graph, int n) {

    vb visited (n);

    forn(i, 0, n) {
        if (!visited[i]) 
            dfs(graph, visited, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e; cin >> v >> e;
    vvi graph (v);

    forn(i, 0, e) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    solve(graph, v);
}