#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// time : O(n) why ? n push + n-1 pops e.g. 5 4 3 2 1 space : O(1) due to stack
// time : O(n) n push + 0 pop e.g. 1 2 3 4 5 space : O(n) due to stack

void f(int* A, int n) {

	stack<int> s;

	vector<int> out;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// cout << -1 << " ";
			out.push_back(-1);
		} else {
			// cout << s.top() << " ";
			out.push_back(s.top());
		}

		s.push(A[i]);
	}

	reverse(out.begin(), out.end());

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}