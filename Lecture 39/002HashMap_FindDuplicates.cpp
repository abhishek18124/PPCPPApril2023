#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {1, 0, 1, 2, 2, 2, 2};
	int n = v.size();

	for (int i = 0; i < v.size(); i++) {

		// int x = v[i];
		// v[x % n] += n;

		v[v[i] % n] += n;

	}

	for (int i = 0; i < v.size(); i++) {

		if (v[i] / n > 1) {
			cout << i << " ";
		}

	}

	cout << endl;



	return 0;
}