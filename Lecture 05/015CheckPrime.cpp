#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	// int i = 2;
	// while(i <= sqrt(n)) { // or i*i <= n
	// 	if(n%i == 0) {
	// 		// you've found a factor 'n' in the range [2, root_n] -> n is a composite number
	// 		cout << "false" << endl;
	// 		return 0;
	// 	}
	// 	i = i+1;
	// }

	// // you did not find any factor of 'n' in the range [2, root_n] -> n is a prime number
	// cout << "true" << endl;

	int i = 2;
	while(i <= sqrt(n)) { // or i*i <= n
		if(n%i == 0) {
			// you've found a factor 'n' in the range [2, root_n] -> n is a composite number
			cout << "false" << endl;
			break;
		}
		i = i+1;
	}

	if(i > sqrt(n)) {
		// you did not find any factor of 'n' in the range [2, root_n] -> n is a prime number
		cout << "true" << endl;
	}

	return 0;
}