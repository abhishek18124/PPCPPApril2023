#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;

	char ch;

	int freq[26] = {0};

	while (true) {

		cin >> ch;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// ch is non-repeating
			q.push(ch);
		}

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			q.pop();
		}

		if (q.empty()) {
			// after reading 'ch', stream doesn't have a non-repeating character
			cout << -1 << " ";
		} else {
			cout << q.front() << " ";
		}

	}


	return 0;
}