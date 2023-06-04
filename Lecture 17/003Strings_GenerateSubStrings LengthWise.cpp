#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	// iterate over all the possible lengths of substring

	for (int l = 1; l <= n; l++) {

		// print all the subString of length 'l'

		for (int i = 0; i <= n - l; i++) {

			cout << str.substr(i, l) << endl;

		}

		cout << endl;

	}

	return 0;
}