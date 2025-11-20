#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
#define forn(i, j, n) for (int i = j; i < n; i++)
#define endl "\n";

bool dfs (vvi& graph, vb& visited, vb& color, int v) {

    visited[v] = true;

    for (auto u : graph[v]) {
        if (!visited[u]) {
            color[u] = !color[v];
            if (!dfs(graph, visited, color, u)) return false;
        }
        else if (color[u] == color[v]) return false;
    }

    return true;
}

void solve (vvi& graph, int n) {

    vb visited (n);
    vb color (n);
    bool res;

    forn(i, 0, n) {
        if (!visited[i]) 
        res = dfs(graph, visited, color, i);
    }

    cout << (res ? "bipartite" : "not bipartite");
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vvi graph (n);

    forn(i, 0, m) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    solve(graph, n);
}