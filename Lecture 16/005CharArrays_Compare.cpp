#include<iostream>
#include<cstring>

using namespace std;

// time : min(m, n) where 'm' is the length of str1 and 'n' is the length of str2

int compareString(char* str1, char* str2) {

	int i = 0; // used to iterate over str1[]
	int j = 0; // used to iterate over str2[]

	while (str1[i] != '\0' and str2[j] != '\0') {

		if (str1[i] < str2[j]) {
			// str1 < str2
			return -1;
		}

		if (str1[i] > str2[j]) {
			// str1 > str2
			return 1;
		}

		i++;
		j++;

	}

	if (str1[i] == '\0' and str2[j] == '\0') {
		// str1 is equal to str2
		return 0;
	}

	if (str1[i] != '\0') {
		// length of str1 > length of str2 therefore str1 > str2
		return 1;
	}

	// length of str1 < length of str2 therefore str1 < str2

	return -1;

}

int main() {

	char str1[] = "azcd";
	char str2[] = "zbcd";

	// int out = compareString(str1, str2);
	int out = strcmp(str1, str2);

	if (out == 0) {
		// both the string are equal
		cout << str1 << " is equal to " << str2 << endl;
	} else if (out < 0) {
		// str1 < str2
		cout << str1 << " < " << str2 << endl;
	} else { // out > 0
		// str1 > str2
		cout << str1 << " > " << str2 << endl;
	}

	return 0;
}