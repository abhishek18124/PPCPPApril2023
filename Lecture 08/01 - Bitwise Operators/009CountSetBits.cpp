#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n = 14;

	int count = 0; // to track the no. of set bits in 'n'

	// while(n > 0) {

	// 	// check if 'n' is odd

	// 	if((n&1) == 1) {
	// 		// 0th bit of n is set i.e. n is odd
	// 		count++;
	// 	}

	// 	n = n>>1;
	
	// }

	// for(int k=0; k<=31; k++) {

	// 	// is the kth bit of 'n' set ?

	// 	if((n>>k)&1) {
	// 		// kth bit of 'n' is set
	// 		count++;
	// 	}

	// }

	for(int k=0; k<ceil(log2(n+1)); k++) {

		// is the kth bit of 'n' set ?

		if((n>>k)&1) {
			// kth bit of 'n' is set
			count++;
		}

	}

	cout << "num. of set bits = " << count << endl;

	return 0;
}