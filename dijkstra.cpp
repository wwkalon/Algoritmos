#include <bits/stdc++.h>
using namespace std;


struct comp {
    bool operator() (tiii& a, tiii& b) {
        return get<0>(a) > get<0>(b);
    }
};

void dijkstra (vvpii& graph, vi& distances, vi& parents, int start, int n) {

    vector<bool> has_visited (n);
    priority_queue<tiii, vector<tiii>, comp> closest;
    
    distances[start] = 0;
    closest.push({0, start, start});
    int i = n;

    while (!closest.empty() && i--) {

        tiii vert = closest.top(); closest.pop();
        while(!closest.empty() && has_visited[get<1>(vert)]) {
            vert = closest.top(); closest.pop();
            if (closest.empty() && has_visited[get<1>(vert)]) return;
        }

        auto [dist, v, p] = vert;
        has_visited[v] = true;
        parents[v] = p;

        for (auto &adj : graph[v]) {

            auto [a, w] = adj;

            if (!has_visited[a] && 
                distances[a] > distances[v] + w) {
                distances[a] = distances[v] + w;
                closest.push({distances[a], a, v});
            }
        }
    }
}

int main(){
    
}