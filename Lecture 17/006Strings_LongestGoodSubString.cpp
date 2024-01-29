#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is not a vowel therefore given string is not a good string
			return false;
		}

	}

	// given string is a good string
	return true;


}

// time : O(n^3)

int longestGoodSubstring(string str) {

	int lsf = 0; // or INT_MIN

	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				// cout << subString << " " << j - i + 1 << endl;
				lsf = max(lsf, j - i + 1);
			}
		}
	}

	return lsf;

}

// time : O(n)

int longestGoodSubstringEfficient(string str) {

	int count = 0;
	int lsf = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			count++;
			lsf = max(lsf, count);
		} else {
			count = 0;
		}

	}

	return lsf;

}

int main() {

	string str = "cbaeicdeiou";


	cout << longestGoodSubstring(str) << endl;

	cout << longestGoodSubstringEfficient(str) << endl;

	return 0;
}