#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector <vector<int>> &g, int s){
    unsigned long n = g.size();
    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    int v;
    int to;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
}
