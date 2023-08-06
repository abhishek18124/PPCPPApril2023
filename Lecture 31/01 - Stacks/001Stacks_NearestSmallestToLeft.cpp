#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void f(int* A, int n) {

	stack<pair<int, int>> s; // <value, index>

	vector<int> out;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and s.top().first >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			out.push_back(-1);
		} else {
			out.push_back(s.top().second);
		}

		s.push({A[i], i});
	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}