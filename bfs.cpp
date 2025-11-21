#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
#define forn(i, j, n) for(int i = j; i < n; i++)
#define endl "\n"
ll imax = 1e11;


void bfs (vvi& graph, vb& visited, vi& dists) {

    queue<int> q;

    dists[0] = 0;
    visited[0] =  true; 

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (auto adj : graph[v]) {
            if (!visited[adj]) {
                q.push(adj);
                visited[adj] = true;
                dists[adj] = dists[v] + 1;
            }
        }
    }
}

void solve (vvi& graph, int n) {

    vb visited (n);
    vi dists (n, imax);

    bfs(graph, visited, dists);
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