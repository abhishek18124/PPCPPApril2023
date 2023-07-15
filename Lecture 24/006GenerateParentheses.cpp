// n <= 8

#include<iostream>

using namespace std;

void f(int n, char* out, int i, int open_count, int close_count) {

	// base case

	if (i == 2 * n) { // open_count == n and close_count == n
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take a decision for the ith position

	// option 1 : use '('

	if (open_count < n) {
		out[i] = '(';
		open_count++;
		f(n, out, i + 1, open_count, close_count);
		open_count--;
		// f(n, out, i + 1, open_count+1, close_count);

	}

	// option 2 : use ')'
	if (close_count < n) {
		out[i] = ')';
		// f(n, out, i + 1, open_count, close_count + 1);
		close_count++;
		f(n, out, i + 1, open_count, close_count);
		close_count--;

	}
}

int main() {

	int n = 2;

	char out[20]; // >= 17

	f(n, out, 0, 0, 0);

	return 0;
}