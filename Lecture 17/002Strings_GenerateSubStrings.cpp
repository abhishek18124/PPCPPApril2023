#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	// iterate over all the possible starting indices

	for (int i = 0; i <= n - 1; i++) {

		// for the given starting index 'i', iterate over all the possible ending indices

		for (int j = i; j <= n - 1; j++) {

			// generate the subString that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }

			// cout << endl;

			// string subString = str.substr(i, j - i + 1);
			// cout << subString << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

	return 0;
}