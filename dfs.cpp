#include <iostream>
#include <vector>

using namespace std;

void dfs(vector <vector<int>> &g, int start, vector<bool> &used){
    cout << start << " "; // Действие над вершиной
    used[start] = true;
    for (int x : g[start])
        if (!used[x])
            dfs(g, x, used);
}
