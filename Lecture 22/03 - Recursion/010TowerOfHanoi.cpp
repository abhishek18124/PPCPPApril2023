/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x
to the end of the string str.

Example
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

void towerOfHanoi(int n, char src, char hlp, char dst) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to move n-1 disks from src to hlp using dst
	towerOfHanoi(n - 1, src, dst, hlp);

	// 2. move the largest disk from src to dst
	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from hlp to dst using src
	towerOfHanoi(n - 1, hlp, src, dst);


}

int main() {

	int n = 3;

	towerOfHanoi(n, 'A', 'B', 'C');

	return 0;
}