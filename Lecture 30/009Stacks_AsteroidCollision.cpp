#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {
		if (ast < 0 and !s.empty() and s.top() > 0) {
			// there will be a collision
			bool flag = true; // assume 'ast' will destroy all the positive asteroids
			while (!s.empty() and s.top() > 0) {

				if (abs(ast) == s.top()) {
					// 'ast' and s.top() will be destroyed
					flag = false;
					s.pop();
					break;
				} else if (abs(ast) < s.top()) {
					// 'ast' will be destroyed
					flag = false;
					break;
				} else {
					// s.top() will be destroyed
					s.pop();
				}
			}

			if (flag == true) {
				// 'ast' has destroyed all the positive asteroids on the top of the stack
				s.push(ast);
			}


		} else {
			s.push(ast);
		}
	}

	vector<int> out;

	while (!s.empty()) {
		out.push_back(s.top());
		s.pop();
	}

	reverse(out.begin(), out.end());

	return out;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> out = asteroidCollision(asteroids);

	for (int i = 0; i < out.size(); i++) {

		cout << out[i] << " ";

	}

	cout << endl;

	return 0;
}