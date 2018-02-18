#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> recoverPath(int finish, int start, vector<int> &parents){
    vector<int> path;
    for (int v=finish; v!=start; v=parents[v])
        path.push_back (v);
    path.push_back (start);
    reverse (path.begin(), path.end());
    return path;
}
