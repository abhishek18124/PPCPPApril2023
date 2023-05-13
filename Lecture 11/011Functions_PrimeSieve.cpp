// m <= 99

#include<iostream>

using namespace std;

int main() {

	int sieve[100]; // based on the constraints

	int m;
	cin >> m;

	for(int i=0; i<=m; i++) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	// for(int i=2; i<=m; i++) {

	// 	// if(sieve[i] == 1) {
	// 	// 	// 'i' is a prime number, mark all of its multiples as non-primes
	// 	// 	for(int j=2*i; j<=m; j+=i) {
	// 	// 		sieve[j] = 0;
	// 	// 	}
	// 	// }

	// 	if(sieve[i] == 1) {
	// 		// 'i' is a prime number, mark all of its multiples as non-primes
	// 		for(int j=i*i; j<=m; j+=i) {
	// 			sieve[j] = 0;
	// 		}
	// 	}

	// }

	for(int i=2; i*i<=m; i++) {

		// if(sieve[i] == 1) {
		// 	// 'i' is a prime number, mark all of its multiples as non-primes
		// 	for(int j=2*i; j<=m; j+=i) {
		// 		sieve[j] = 0;
		// 	}
		// }

		if(sieve[i] == 1) {
			// 'i' is a prime number, mark all of its multiples as non-primes
			for(int j=i*i; j<=m; j+=i) {
				sieve[j] = 0;
			}
		}

	}


	for(int i=2; i<=m; i++) {

		if(sieve[i] == 1) {
			cout << i << " ";
		}

	}



	return 0;
}