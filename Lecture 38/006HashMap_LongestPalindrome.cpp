#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {

	string str = "abcdd";

	unordered_set<char> hashSet;
	int count = 0;
	for (char ch : str) {
		if (hashSet.find(ch) != hashSet.end()) {
			count += 2;
			hashSet.erase(ch);
		} else {
			hashSet.insert(ch);
		}
	}

	if (hashSet.size() > 0) {
		count++;
	}

	cout << count << endl;

	return 0;
}