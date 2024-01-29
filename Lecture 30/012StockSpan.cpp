#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// void f(int* A, int n) {

// 	stack<pair<int, int>> s; // <vallue, index>

// 	vector<int> out;

// 	for (int i = 0; i <= n - 1; i++) {

// 		// find the index of nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j;

// 		if (s.empty()) {
// 			j = -1;
// 		} else {
// 			j = s.top().second;
// 		}

// 		int span_ith_day = i - j;

// 		out.push_back(span_ith_day);

// 		s.push({A[i], i}); // make_pair(A[i], i)
// 	}

// 	for (int i = 0; i < out.size(); i++) {
// 		cout << out[i] << " ";
// 	}

// 	cout << endl;

// }

void f(int* A, int n) {

	stack<int> s; // <index>

	vector<int> out;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			j = -1;
		} else {
			j = s.top();
		}

		int span_ith_day = i - j;

		out.push_back(span_ith_day);

		s.push(i);
	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}



int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}