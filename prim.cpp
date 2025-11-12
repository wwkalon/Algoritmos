#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <numeric>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vvpii =  vector<vector<pii>>;
#define forn(i, j, n) for(int i = j; i < n; i++)
#define endl "\n"
ll imax = 1e12;

struct comp {
    bool operator() (tiii& a, tiii& b) {
        return get<0>(a) > get<0>(b);
    }
};


void prim (vvpii& graph, vi& distances, vi& parents, int n) {

    vb has_visited (n);
    priority_queue<tiii, vector<tiii>, comp> closest;

    distances[0] = 0;
    parents[0] = 0;
    closest.push({0, 0, 0});
    int e = 0;

    while (!closest.empty() && e < n - 1) {

        tiii vert = closest.top(); closest.pop();
        while (!closest.empty() && has_visited[get<1>(vert)]) {
            vert = closest.top(); closest.pop();
            if (closest.empty() && has_visited[get<1>(vert)]) return;
        }

        auto [dist, v, p] = vert;
        has_visited[v] = true;
        parents[v] = p;

        for (auto &adj : graph[v]) {
            
            auto [a, w] = adj;

            if (!has_visited[a] && distances[a] > w) {
                distances[a] = w;
                closest.push({w, a, v});
            }
        }

        e++;
    }
}

void solve (vvpii& graph, int n) {

    vi distances (n, imax);
    vi parents (n, -1);
    prim(graph, distances, parents, n);

    int s = accumulate(distances.begin(), distances.end(), 0);
    cout << s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e; cin >> v >> e;
    vvpii graph (v);

    forn(i, 0, e) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }

    solve(graph, v);
}