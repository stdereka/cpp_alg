#include <iostream>
#include <vector>

using namespace std;

vector<int> dijkstra(vector < vector < pair<int,int> > > g, int s){ // Граф считывать через readGraphWithWeights
    const int INF = 1000000000;
    unsigned long n = g.size();
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    vector<char> u (n);
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return d;
}
