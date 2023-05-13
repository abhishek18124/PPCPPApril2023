#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {
	int rn = sqrt(n);
	for(int i=2; i<=rn; i++) {
		// check if 'i' is a factor of 'n'
		if(n%i == 0) {
			// you've found a factor of 'n' in the range [2, n-1]
			return false;
		}
	}
	return true;
}

void printPrimes(int m) {

	for(int n=2; n<=m; n++) {
		// check if 'n' is prime
		if(isPrime(n)) {
			cout << n << " ";
		}
	}
	cout << endl;

}

int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	printPrimes(m);
	
	return 0;
}