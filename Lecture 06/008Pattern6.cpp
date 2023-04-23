#include<iostream>

using namespace std;

int main() {

	int n = 5;

	for(int i=1; i<=n; i++) {

		// in the ith row, print (n-i) spaces
		for(int j=1; j<=n-i; j++) {
			cout << "  ";
		}

		// followed by i nos. in the increasing order starting with i
		
		// for(int j=1, num=i; j<=i; j++, num++) {
		// 	cout << num << " ";
		// }

		int num = i;

		for(int j=1; j<=i; j++) {
			cout << num << " ";
			num++;
		}


		cout << endl;

	}

	return 0;
}