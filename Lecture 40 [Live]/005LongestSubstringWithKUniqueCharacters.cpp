#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int uniqueCount = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	// time : O(n)
	// space : O(n) due to freqMap when s has all unique characters

	while (j < n) {

		// expand the window

		// add s[j] to the window

		freqMap[s[j]]++;
		if (freqMap[s[j]] == 1) {
			// s[j] is seen in the window for the 1st time
			uniqueCount++;
		}

		// check for the violation of the window property

		if (uniqueCount > k) {

			// window property is violated, fix it by shrinking the window

			while (uniqueCount > k) {

				// delete s[i] from the window
				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					uniqueCount--;
				}
				i++;

			}

		}

		// check for the validity of the window, and update the answer

		if (uniqueCount == k) {

			// you've found a valid window

			max_len = max(max_len, j - i + 1);

		}

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}