#include<iostream>

using namespace std;

int main() {

	int x = 10;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;

	cout << endl;

	char ch = 'A';
	cout << "ch = " << ch << endl;
	cout << "&ch = " << &ch << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;

	double y = 3.14;
	cout << "y = " << y << endl;
	cout << "&y = " << &y << endl;
	cout << "sizeof(&y) = " << sizeof(&y) << "B" << endl;

	float z = 1.25;
	cout << "z = " << z << endl;
	cout << "&z = " << &z << endl;
	cout << "sizeof(&z) = " << sizeof(&z) << "B" << endl;

	return 0;
}