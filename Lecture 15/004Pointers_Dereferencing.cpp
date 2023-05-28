#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *xptr = &x;

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	cout << "*xptr = " << *xptr << endl;


	double y = 3.14;
	double* yptr = &y;

	cout << "y = " << y << endl;
	cout << "sizeof(y) = " << sizeof(y) << endl;
	cout << "yptr = " << yptr << endl;
	cout << "sizeof(yptr) = " << sizeof(yptr) << endl;
	cout << "*yptr = " << *yptr << endl;

	int z = 253;
	char* ptr = (char*)&z;
	cout << (int)*ptr << endl;

	int w = 100;
	double* dptr = (double*)&w;
	cout << *dptr << endl;

	return 0;
}