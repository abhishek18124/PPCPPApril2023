#include<iostream>

using namespace std;

int multiply(int a, int b) {

	cout << "inside multiply() : before ++ : a = " << a << " b = " << b << endl;

	a++;
	b++;

	cout << "inside multiply() : after ++ : a = " << a << " b = " << b << endl;
	
	return a*b;

}

int main() {

	int a = 10;
	int b = 20;

	cout << "inside main() : before multiply() : a = " << a << " b = " << b << endl;

	cout << multiply(a, b) << endl;

	cout << "inside main() : after multiply() : a = " << a << " b = " << b << endl;

	return 0;
}