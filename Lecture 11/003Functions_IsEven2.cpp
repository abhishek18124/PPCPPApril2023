#include<iostream>

using namespace std;

bool isEven(int n) {

	return n%2 == 0;

}

int main() {

	bool ans;

	ans = isEven(5);

	cout << ans << endl;

	bool ans2 = isEven(4);
	
	cout << ans2 << endl;

	cout << isEven(6) << endl;

	bool ans3 = isEven(9);

	if(ans3 == true) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	if(ans3) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	if(isEven(9)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	ans3 == true ? cout << "true" << endl : cout << "false" << endl;

	ans3 ? cout << "true" << endl : cout << "false" << endl;

	isEven(9) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}