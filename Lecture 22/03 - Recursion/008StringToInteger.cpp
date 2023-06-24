#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (str.empty()) { // str.size() == 0 or n == 0 or str == ""
		return 0;
	}

	// recursive case

	string subString = str.substr(0, n - 1);
	int integerFromMyFriend = stringToInteger(subString, n - 1);

	return integerFromMyFriend * 10 + (str[n - 1] - '0');

}

int main() {

	string str = "12345";
	int n = str.size();

	int x = stringToInteger(str, n);

	cout << x << endl;
	cout << x + 1 << endl;

	return 0;
}