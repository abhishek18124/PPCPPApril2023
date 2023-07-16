/*

Suppose there is a ladder with n steps. A person standing at the bottom of the ladder and wants to
reach to its top. Assume the person can take atmost k steps at a time. Then, count the number
of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> path;
vector<vector<int>> paths;

// int f(int n, int k, int i) {

// 	// base case

// 	if (i == n) {
// 		// for (int jump : path) {
// 		// 	cout << jump << " ";
// 		// }
// 		// cout << endl;
// 		paths.push_back(path);
// 		return 1;
// 	}

// 	// recursive case

// 	// count no. of ways to go from i to n

// 	int count = 0;

// 	for (int j = 1; j <= k; j++) {

// 		if (i + j <= n) {
// 			path.push_back(j);
// 			count += f(n, k, i + j);
// 			path.pop_back(); // backtracking step
// 		} else {
// 			break;
// 		}
// 	}

// 	return count;

// }

int f(int n, int k, int i) {

	// base case

	if (i == n) {
		// for (int jump : path) {
		// 	cout << jump << " ";
		// }
		// cout << endl;
		paths.push_back(path);
		return 1;
	}

	if (i > n) {
		return 0;
	}

	// recursive case

	// count no. of ways to go from i to n

	int count = 0;

	for (int j = 1; j <= k; j++) {
		path.push_back(j);
		count += f(n, k, i + j);
		path.pop_back(); // backtracking step
	}

	return count;

}


int main() {

	int n = 4;
	int k = 3;

	cout << f(n, k, 0) << endl;

	for (vector<int> path : paths) {
		for (int jump : path) {
			cout << jump << " ";
		}
		cout << endl;
	}

	return 0;
}