#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int main() {

	vector<int> v = {10, 20, 30, 10, 20,};

	// unordered_map<int, int> freqMap;

	// for (int i = 0; i < v.size(); i++) {
	// 	freqMap[v[i]]++;
	// 	// if(freqMap[v[i]] > 1) {
	// 	// 	// you've found a duplicate
	// 	// }
	// }

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

	// bool flag = false; // assume no duplicates

	// for (pair<int, int> p : freqMap) {
	// 	if (p.second > 1) {
	// 		// you've found a duplicate
	// 		flag = true;
	// 		break;
	// 	}
	// }

	// if (flag == true) {
	// 	cout << "duplicate found" << endl;
	// } else {
	// 	cout << "duplicate not found" << endl;
	// }

	bool flag = false; // assume no duplicates

	unordered_set<int> hashSet;

	for (int i = 0; i < v.size(); i++) {
		if (hashSet.find(v[i]) != hashSet.end()) {
			flag = true;
			break;
		}
		hashSet.insert(v[i]);
	}

	if (flag == true) {
		cout << "duplicate found" << endl;
	} else {
		cout << "duplicate not found" << endl;
	}
	return 0;
}