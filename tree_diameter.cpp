#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using pii = pair<int,int>;
#define forn(i, j, n) for(int i = j; i < n; i++)
#define endl "\n"
ll imax = 1e11;


pii bfs (vvi& graph, int s, int n) {

    vb visited (n);
    vi dists (n, imax); 
    queue<int> q;

    dists[s] = 0;
    visited[s] =  true;
    
    int max_dist = 0;
    int farthest = s;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        if (dists[v] > max_dist) {
            max_dist = dists[v];
            farthest = v;
        }

        for (auto adj : graph[v]) {
            
            if (!visited[adj]) {
                q.push(adj);
                visited[adj] = true;
                dists[adj] = dists[v] + 1;
            }
        }
    }

    return {max_dist, farthest};
}

void solve (vvi& graph, int n) {

    auto [d, f_root] = bfs(graph, 0, n);
    auto [diameter, v] = bfs(graph, f_root, n);
    cout << diameter;
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