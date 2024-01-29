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

string moveX(string str) {

	// base case
	if (str.empty()) { // str.size() == 0 or str == ""
		return str;
	}

	// recursive case

	string subString = str.substr(1);
	string subStringFromMyFriend = moveX(subString);

	char ch = str[0];

	if (ch == 'x') {
		return subStringFromMyFriend + string(1, ch);
	}

	return string(1, ch) + subStringFromMyFriend;

}

int main() {

	string str = "cxxbx";

	cout << moveX(str) << endl;

	return 0;
}