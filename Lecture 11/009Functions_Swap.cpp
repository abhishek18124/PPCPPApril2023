#include<iostream>

using namespace std;

void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	cout << "before swap a = " << a << " b = " << b << endl;

	// swap(a, b);

	mySwap(a, b);

	cout << "after swap a = "  << a << " b = " << b << endl;

	return 0;
}