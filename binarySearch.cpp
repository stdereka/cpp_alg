#include <iostream>
using namespace std;


int searchBinary(int arr[], int left, int right, int key){
    int midd = 0;
    while (true)
    {
        midd = (left + right) / 2;

        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}


int main(){
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
        cin >> Arr[i];
    int key;
    cin >> key;
    cout << searchBinary(Arr, 0, n-1, key);
}
