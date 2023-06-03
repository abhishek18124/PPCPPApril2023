#include<iostream>

using namespace std;

// sort : 2nlogn + n = 2*8*log8 + 8 = 2*8*3 + 8 = 56 steps
// 2*4*log4 + 4 = 2*4*2 + 4 = 20 steps

// total steps = n+n+26
// 8+8+26 = 42 steps
// 4+4+26 = 30 steps

bool isAngram(char* str1, char* str2) {

	// 1. build a freq[] corr. to str1[] - n steps

	int freq1[26] = {};

	for (int i = 0; str1[i] != '\0'; i++) {
		char ch = str1[i];
		int idx = ch - 'a';
		freq1[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << freq1[i] << " ";
	}


	// 2. build a freq[] corr. to str2[] - n steps

	int freq2[26] = {};

	for (int i = 0; str2[i] != '\0'; i++) {
		freq2[str2[i] - 'a']++;
	}

	cout << endl;


	for (int i = 0; i < 26; i++) {
		cout << freq2[i] << " ";
	}

	cout << endl;

	// 3. compare freq1[] with freq2[] - 26

	for (int i = 0; i < 26; i++) {
		if (freq1[i] != freq2[i]) {
			return false;
		}
	}

	return true;

}

int main() {

	char str1[] = "aaabbbccc";
	char str2[] = "aaabbbbcc";

	isAngram(str1, str2) ? cout << "anagram" << endl :
	                            cout << "not anagram" << endl;

	return 0;
}