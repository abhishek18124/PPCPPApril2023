#include<iostream>

using namespace std;

int main() {
	
	const int y = 500;

	cout << y << endl;

	// y = y+100; // error : since y is declared as a const, it is read-only 

	cout << y << endl;

	// float const z; // const variable must be always initialized
	
	return 0;
}