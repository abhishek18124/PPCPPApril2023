#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	// for(int i=0; str[i] != '\0'; i++) {

	// 	char ch = str[i];

	// }

	// for (char ch : str) {

	// }

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is not a vowel therefore given string is not a good string
			return false;
		}

	}

	// given string is a good string
	return true;


}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good string" << endl :
	                         cout << "not a good string" << endl;

	return 0;
}