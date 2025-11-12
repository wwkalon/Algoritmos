#include <vector>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vtiii = vector<tiii>;
#define forn(i, j, n) for(int i = j; i < n; i++)
#define endl "\n"
ll imax = 1e12;

class dsu {
public:

    vi reps;

    dsu (int n) : reps(vi (n)) {
        forn(i, 0, n) {
            reps[i] = i;
        }
    }

    int find (int cur) {

        if (reps[cur] == cur) return cur;
        reps[cur] = find(reps[cur]);
        return reps[cur];
    }

    void make_union (int a, int b) {

        int root1 = find(a);
        int root2 = find(b);
        if (root1 != root2) reps[root2] = root1;
    }
};


struct comp {
    bool operator() (tiii& a, tiii& b) {
        return get<0>(a) > get<0>(b);
    }
};


int kruskal (vtiii& edges, int n) {

    dsu forest(n);
    priority_queue<tiii, vector<tiii>, comp> min_edges (edges.begin(), edges.end());
    int n_edges = 0;
    int total_dist = 0;

    while (n_edges < n - 1) {

        auto [w, v1, v2] = min_edges.top(); min_edges.pop();
        if (forest.find(v1) != forest.find(v2)) {
            forest.make_union(v1, v2);
            total_dist += w;
            n_edges++;
        }
    }

    return total_dist;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e; cin >> v >> e;
    vtiii edges (e);

    forn(i, 0, e) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        edges[i] = {w, v1, v2};
    }

    int res = kruskal(edges, v);
    cout << res;
}