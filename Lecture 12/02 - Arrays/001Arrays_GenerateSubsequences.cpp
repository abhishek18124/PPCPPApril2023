#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	for(int i=0; i<(1<<n); i++) {
		
		for(int j=0; j<n; j++) {

			if((i>>j)&1) {
				cout << arr[j] << " ";
			}

		}

		cout << endl;

	}

	cout << endl;

	return 0;
}
