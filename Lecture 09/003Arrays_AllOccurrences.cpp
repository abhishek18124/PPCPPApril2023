#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 10;
	
	// int count = 0; // track the no. of occ. of the 't' in the given array

	bool flag = false; // assume 't' is not present

	for(int i=0; i<n; i++) {
		if(arr[i] == t) {
			// you've found an occ. of the 't' at the index 'i'
			cout << i << " ";
			// count++;
			flag = true;
		}
	}

	// if(flag == false) {
	// 	// your initial assumption was true : 't' is not present
	// 	cout << -1 << endl;
	// }

	if(!flag) {
		cout << -1 << endl;
	}

	// if(count == 0) {
	// 	// you've not found the 't' in the given array
	// 	cout << -1 << endl;
	// }


	return 0;
}