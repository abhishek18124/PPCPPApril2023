#include<iostream>

using namespace std;

int main() {

    int arr[][4] = {{10, 15, 20, 25},
        {30, 35, 40, 45}
    };

    // int arr[3][4]; // or {} to init with zero

    // memset(arr, 0, sizeof(arr)); // to init with zero

    int m = 3;
    int n = 4;

    for (int i = 0; i < m; i++) {
        for (int  j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}