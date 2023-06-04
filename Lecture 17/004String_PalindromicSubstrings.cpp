#include<iostream>

using namespace std;

// bool isPalindrome(string str) {

// 	int i = 0;
// 	int j = str.size() - 1;

// 	while (i < j) {

// 		if (str[i] != str[j]) {
// 			return false;
// 		}

// 		i++;
// 		j--;

// 	}

// 	return true;

// }


// // time : O(n^3)

// int countPalindromicSubstrings(string s) {

// 	int count = 0; // to track the no. of palindromic substrings in the given string

// 	int n = s.size();

// 	for (int i = 0; i <= n - 1; i++) {
// 		for (int j = i; j <= n - 1; j++) {
// 			string subString = s.substr(i, j - i + 1);
// 			if (isPalindrome(subString)) {
// 				count++;
// 			}
// 		}
// 	}

// 	return count;

// }


int countPalindromicSubstringsEfficient(string s) {

	int count = 0;

	int n = s.size();

	// 1. find the no. of odd-length palindromic subString

	// iterate over all the possible centers of an odd-length palindromic subString

	for (int i = 0; i <= n - 1; i++) {

		// count the no. of odd length palindromic subString around the ith character

		int j = 0;
		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {
			count++;
			j++;
		}

	}

	// 2. find the no. of even-length palindromic subString

	// iterate over all the possible centers of an even-length palindromic subString

	for (double i = 0.5; i < n; i++) {

		// count the no. of even length palindromic subString around the ith center

		double j = 0.5;

		while (i - j >= 0 and i + j <= n - 1 and s[int(i - j)] == s[int(i + j)]) {
			count++;
			j++;
		}

	}

	cout << count << endl;

	return count;

}

int main() {

	string s = "abaaba";

	// cout << countPalindromicSubstrings(s) << endl;
	cout << countPalindromicSubstringsEfficient(s) << endl;

	return 0;
}