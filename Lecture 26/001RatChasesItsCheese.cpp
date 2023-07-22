#include<iostream>

using namespace std;

void printPath(char path[][10], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == m || i == -1 || j == n || j == -1) {
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {

// 		path[i][j] = '1';
// 		printPath(path, m, n);
// 		path[i][j] = '0';

// 		return;

// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	// recursive case

// 	if (path[i][j] == '1') {
// 		return;
// 	}

// 	// while standing at the (i, j)th cell, decide the next step

// 	path[i][j] = '1';

// 	// 1. move right
// 	f(maze, path, m, n, i, j + 1);

// 	// 2. move left
// 	f(maze, path, m, n, i, j - 1);

// 	// 3. move up
// 	f(maze, path, m, n, i - 1, j);

// 	// 4. move down
// 	f(maze, path, m, n, i + 1, j);

// 	path[i][j] = '0';
// }

// void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == m || i == -1 || j == n || j == -1) {
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {

// 		path[i][j] = '1';
// 		printPath(path, m, n);
// 		path[i][j] = '0';

// 		return;

// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	// recursive case

// 	// while standing at the (i, j)th cell, decide the next step

// 	path[i][j] = '1';
// 	maze[i][j] = 'X';

// 	// 1. move right
// 	f(maze, path, m, n, i, j + 1);

// 	// 2. move left
// 	f(maze, path, m, n, i, j - 1);

// 	// 3. move up
// 	f(maze, path, m, n, i - 1, j);

// 	// 4. move down
// 	f(maze, path, m, n, i + 1, j);

// 	path[i][j] = '0';
// 	maze[i][j] = '0';
// }

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


void f(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || i == -1 || j == n || j == -1) {
		return;
	}

	if (i == m - 1 and j == n - 1) {

		path[i][j] = '1';
		printPath(path, m, n);
		path[i][j] = '0';

		return;

	}

	if (maze[i][j] == 'X') {
		return;
	}

	// recursive case

	// while standing at the (i, j)th cell, decide the next step

	path[i][j] = '1';
	maze[i][j] = 'X';

	for (int k = 0; k < 4; k++) {
		f(maze, path, m, n, i + dx[k], j + dy[k]);
	}

	path[i][j] = '0';
	maze[i][j] = '0';
}


int main() {


	char maze[][10] = {"0X00",
	                   "000X",
	                   "X0X0",
	                   "X00X",
	                   "XX00"
	                  };


	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000",
	                   "0000"
	                  };
	int m = 5;
	int n = 4;

	f(maze, path, m, n, 0, 0);

	return 0;
}