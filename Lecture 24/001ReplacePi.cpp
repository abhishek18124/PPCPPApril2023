/*

Given string str of size n, design a recursive algorithm to replace all
occurrences of "pi" with "3.14" in the given string and then print it.

Example :
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

Constraints :

	1 < n < 10

*/

#include<iostream>

using namespace std;

void f(char* inp, int i) {

	// base case

	if (inp[i] == '\0') {
		return;
	}

	// recursive case

	// replace all the "pi's" with "3.14" in inp[i...]

	if (inp[i] == 'p' and inp[i + 1] == 'i') {

		// replace (i, i+1)th char. with "3.14"

		// 1. shift all the char. starting from the (i+2)th index 2-steps to the right

		int j = i + 2;
		while (inp[j] != '\0') {
			j++;
		}

		while (j >= i + 2) {
			inp[j + 2] = inp[j];
			j--;
		}

		inp[i] = '3';
		inp[i + 1] = '.';
		inp[i + 2] = '1';
		inp[i + 3] = '4';

		// 2. recursively, replace all the "pi's" with "3.14" in inp[i+4...]

		f(inp, i + 4);

	} else {

		// recursively, replace all the "pi's" with "3.14" in inp[i+1...]

		f(inp, i + 1);


	}

}

int main() {

	char inp[20] = "pippii";

	f(inp, 0);

	cout << inp << endl;

	return 0;
}
