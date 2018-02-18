#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> dijkstra(vector < vector < pair<int,int> > > g, int s){
    const int INF = 1000000000;
    unsigned long n = g.size();
    vector<int> d (n, INF),  p (n, -1);
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
    return p;
}

vector<int> recoverPath(int finish, int start, vector<int> &parents){
    vector<int> path;
    for (int v=finish; v!=start; v=parents[v])
        path.push_back (v);
    path.push_back (start);
    reverse (path.begin(), path.end());
    return path;
}

int main() {
    unsigned long numVertex, numEdge;
    cin >> numVertex;
    cin >> numEdge;
    vector < vector < pair<int,int> > > Graph (numVertex);
    int a, b, weight;
    for (int i = 0; i < numEdge; ++i){
        cin >> a;
        cin >> b;
        cin >> weight;
        pair<int,int> A = {b, weight};
        pair<int,int> B = {a, weight};
        Graph[a].emplace_back(A);
        Graph[b].emplace_back(B);
    }
    int k;
    cin >> k;
    vector<vector<int>> paths;
    map<int, pair<int, int >> translation;
    map<pair<int, int>, int> retranslation;
    set<pair<int, int >> S;
    for (int j = 0; j < numVertex; j++){
        for (auto x : Graph[j]){
            int u, v;
            u = j;
            v = x.first;
            pair<int, int> A, B, C, D, E, F;
            A = {u, 0}; B = {v, 1}; C = {v, 0}; D = {u, 1}; E = {v, 2}; F = {u, 2};
            S.insert(A); S.insert(B); S.insert(C); S.insert(D); S.insert(E); S.insert(F);
        }
    }
    int iter = 0;
    for (auto x : S){
        translation[iter] = x;
        retranslation[x] = iter;
        iter ++;
    }
    for (int i = 0; i < k; i++){
        int from, to;
        cin >> from;
        cin >> to;
        vector < vector < pair<int,int> > > utilGraph(numVertex*3);
        for (int j = 0; j < numVertex; j++){
            int u, v, we;
            for (pair<int,int> x : Graph[j]){
                u = j;
                v = x.first;
                we = x.second;
                pair<int, int> A, B, C, D, E, F;
                A = {u, 0}; B = {v, 1}; C = {v, 0}; D = {u, 1}; E = {v, 2}; F = {u, 2};
                utilGraph[retranslation[A]].emplace_back(retranslation[B], we);
                utilGraph[retranslation[C]].emplace_back(retranslation[D], we);
                utilGraph[retranslation[D]].emplace_back(retranslation[E], we);
                utilGraph[retranslation[B]].emplace_back(retranslation[F], we);
                utilGraph[retranslation[F]].emplace_back(retranslation[C], we);
                utilGraph[retranslation[E]].emplace_back(retranslation[A], we);
            }
        }
        pair<int, int> FROM = {from, 0};
        pair<int, int> TO = {to, 1};
        int start, finish;
        start = retranslation[FROM];
        finish = retranslation[TO];
        vector<int> parents = dijkstra(utilGraph, start);
        vector<int> path = recoverPath(finish, start, parents);
        paths.emplace_back(path);
    }
    for (auto x : paths) {
        for (int y : x) {
            cout << translation[y].first << " ";
        }
        cout << endl;
    }
}
