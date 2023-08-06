#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void f(int* A, int n) {

	stack<pair<int, int>> s; // <value, index>

	vector<int> out;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and s.top().first >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			out.push_back(n);
		} else {
			out.push_back(s.top().second);
		}

		s.push({A[i], i});
	}

	reverse(out.begin(), out.end());

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}