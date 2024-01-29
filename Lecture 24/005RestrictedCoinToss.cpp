// n <= 10

#include<iostream>

using namespace std;

// void f(int n, char* out, int i, int j) {

// 	// base case

// 	if (i == n) {
// 		// you've taken decisions for all the n coins
// 		out[j] = '\0';
// 		cout << out << endl;
// 		return;
// 	}

// 	// recursive case

// 	// take decisions for the remaining n-i coins starting from the ith coin

// 	// for the ith coin, we've two options

// 	// option 1 : ith coin shows head

// 	if (i == 0 || out[j - 1] != 'H') {
// 		out[j] = 'H';
// 		f(n, out, i + 1, j + 1);
// 	}

// 	// option 2 : ith coin shows tail

// 	out[j] = 'T';
// 	f(n, out, i + 1, j + 1);

// }

// int main() {

// 	int n = 3;

// 	char out[10];

// 	f(n, out, 0, 0);

// 	return 0;
// }

void f(int n, char* out, int i) {

	// base case

	if (i == n) {
		// you've taken decisions for all the n coins
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take decisions for the remaining n-i coins starting from the ith coin

	// for the ith coin, we've two options

	// option 1 : ith coin shows head

	if (i == 0 || out[i - 1] != 'H') {
		out[i] = 'H';
		f(n, out, i + 1);
	}

	// option 2 : ith coin shows tail

	out[i] = 'T';
	f(n, out, i + 1);

}

int main() {

	int n = 3;

	char out[10];

	f(n, out, 0);

	return 0;
}