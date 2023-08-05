#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void f(int* A, int n) {

	stack<int> s;

	vector<int> out;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			out.push_back(-1);
		} else {
			out.push_back(s.top());
		}

		s.push(A[i]);
	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}