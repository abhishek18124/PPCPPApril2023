#include<iostream>
#include<bitset>

using namespace std;

int main() {

	int n = 51;
	int k = 5;

	// approach 1

	cout << bitset<32>(n) << endl;

	if(((n>>k)&1) == 0) {
		cout << k << "th bit of " << n << " is not set" << endl;
	} else { // expr. evaluates to one
		cout << k << "th bit of " << n << " is set" << endl;
	}

	((n>>k)&1) == 0 ? cout << k << "th bit of " << n << " is not set" << endl :
	                  cout << k << "th bit of " << n << " is set" << endl;

	!((n>>k)&1) ? cout << k << "th bit of " << n << " is not set" << endl :
	             cout << k << "th bit of " << n << " is set" << endl;

	if(((n>>k)&1) == 1) {
		cout << k << "th bit of " << n << " is set" << endl;
	} else {
		cout << k << "th bit of " << n << " is not set" << endl;
	}

	if(((n>>k)&1)) {
		cout << k << "th bit of " << n << " is set" << endl;
	} else {
		cout << k << "th bit of " << n << " is not set" << endl;
	}

	// approach 2

	if(((1<<k)&n) == 0) {
		cout << k << "th bit of " << n << " is not set" << endl;
	} else { // expr. evaluates to 2^k ( > zero )
		cout << k << "th bit of " << n << " is set" << endl;
	}

	
	return 0;
}