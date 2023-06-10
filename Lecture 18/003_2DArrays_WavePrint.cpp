#include<iostream>

using namespace std;

int main() {

	int arr[][3] = {{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	for (int j = 0; j < n; j++) {

		// print the jth column

		if (j % 2 == 0) {

			// jth column is an even column

			for (int i = 0; i < m; i++) {

				cout << arr[i][j] << " ";

			}

		} else {

			// jth column is an odd column

			for (int i = m - 1; i >= 0; i--) {

				cout << arr[i][j] << " ";

			}

		}

	}

	return 0;
}