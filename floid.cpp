#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int x, y;
    cin >> x;
    cin >> y;
    int w[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
            if (w[i][j]==-1) {
                w[i][j] = 999999;
            }
        }
    }
    int A[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            A[i][j] = w[i][j];
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                A[i][j] = std::min(A[i][j], A[i][k] + A[k][j]);


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == 999999) {
                A[i][j] = -1;
            }
        }
    }

    cout << A[x-1][y-1];
    return 0;
}
