// #include<iostream>
// #include<set>

// using namespace std;

// set<string> s;

// void f(char* inp, int i) {

// 	// base case
// 	if (inp[i] == '\0') {
// 		// cout << inp << endl;
// 		s.insert(string(inp));
// 		return;
// 	}

// 	// recursive case

// 	// take a decision for the ith position

// 	int n = strlen(inp);
// 	for (int j = i; j < n; j++) {
// 		swap(inp[i], inp[j]);
// 		f(inp, i + 1);
// 		swap(inp[i], inp[j]); // backtracking step
// 	}

// }

// int main() {

// 	char inp[] = "aabc";

// 	f(inp, 0);

// 	for(string perm : s) {
// 		cout << perm << " ";
// 	}

// 	cout << endl;

// 	return 0;
// }



#include<iostream>
#include<cstring>

using namespace std;

void generatePermutations(char* inp, int n, int i) {

	// base case

	if (inp[i] == '\0') { // or i == n
		cout << inp << endl;
		return;
	}

	// recursive case

	// generate unique permutations for inp[i...n-1]

	// make a decision for the ith position

	for (int j = i; j < n; j++) {

		bool flag = true; // assume you can assign inp[j] to the ith pos.

		for (int k = j + 1; k < n; k++) {
			if (inp[k] == inp[j]) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			swap(inp[i], inp[j]);
			generatePermutations(inp, n, i + 1);
			swap(inp[i], inp[j]);

		}
	}
}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	generatePermutations(inp, n, 0);

	return 0;
}