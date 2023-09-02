#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	vector<int> v = {1, 2, 3, 1, 2, 1};
	int k = 2;

	unordered_map<int, int> indexMap;
	bool flag = false; // no valid pair present

	for (int i = 0; i < v.size(); i++) {

		if (indexMap.find(v[i]) != indexMap.end()) {
			int j = indexMap[v[i]];
			if (i - j <= k) {
				flag = true;
				break;
			}
		}

		indexMap[v[i]] = i;

	}

	if (flag == true) {
		cout << "pair found" << endl;
	} else {
		cout << "no valid pair found" << endl;
	}

	return 0;
}