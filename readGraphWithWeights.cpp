#include <iostream>
#include <vector>

using namespace std;

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
}
