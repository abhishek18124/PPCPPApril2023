/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> generate all the paths from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

	       {"1100", {"1000", {"1000",
            "0100",	 "1100",  "1000",
            "0110",  "0110",  "1110",
            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

void printPaths(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m or j == n) {
		return;
	}

	if (i == m - 1 and j == n - 1) {
		// you've readched the destination (assume destination is not blocked)

		path[i][j] = '1'; // set the destination cell to 1

		for (int ii = 0; ii < m; ii++) {
			for (int jj = 0; jj < n; jj++) {
				cout << path[ii][jj] << " ";
			}
			cout << endl;
		}

		cout << endl;

		path[i][j] = '0';

		return;

	}

	if (maze[i][j] == 'X') {
		return;
	}

	// recursive case

	path[i][j] = '1';

	// move right

	printPaths(maze, path, m, n, i, j + 1);

	// move down

	printPaths(maze, path, m, n, i + 1, j);

	path[i][j] = '0'; // backtracking step

	return;

}


int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "000X",
	                   "0X00"
	                  };


	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000"
	                  };
	int m = 4;
	int n = 4;

	printPaths(maze, path, m, n, 0, 0);

	return 0;
}
