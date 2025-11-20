//  KAHN'S TOPOSORTING

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define forn(i, j, n) for (int i = j; i < n; i++)
#define endl "\n";

void toposort (vvi& graph, vi sorted, int n) {

    vi indeg (n, 0);
    queue<int> q;

    forn(i, 0, n) {
        for (auto adj : graph[i])
            indeg[adj]++;
    }

    forn(i, 0, n) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {

        int v = q.front(); q.pop();
        sorted.push_back(v);

        for (auto adj : graph[v]) {
            indeg[adj]--;
            if (indeg[adj] == 0) q.push(adj);
        }
    }
}

void solve (vvi& graph, int n) {

    vi sorted;
    toposort(graph, sorted, n);

    if (sorted.size() < n) {
        cout << "there's a cycle"; return;
    }

    for (auto num : sorted) {
        cout << num <<  " ";
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vvi graph (n);

    forn(i, 0, m) {
        int v1, v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }

    solve(graph, n);
}