#include <iostream>
#include <vector>

using namespace std;

int main(){
    unsigned long numEdge, numVertex;
    cin >> numVertex;
    cin >> numEdge;
    vector<vector<int>> Graph(numVertex);
    int a, b;
    for (int i = 0; i < numEdge; ++i){
        cin >> a;
        cin >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a); // если неорграф
    }
    // Только для тестирования
    /*for (vector<int> x : Graph) {
        for (int y : x)
            cout << y << " ";
        cout << endl;
    }*/
}
