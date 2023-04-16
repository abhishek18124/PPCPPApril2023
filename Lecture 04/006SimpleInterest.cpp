#include<iostream>

using namespace std;

int main() {

	int p;
	cout << "Enter the value of principle : ";
	cin >> p;

	int r;
	cout << "Enter the value of rate :" ;
	cin >> r;

	int t;
	cout << "Enter the value of time : ";
	cin >> t;

	float si = p*r*t/100; // int/int -> int

	cout << "simple interest = " << p*r*t/100 << endl;
	cout << "simple interest = " << (p*r*t)/100.0 << endl;
	cout << "simple interest = " << (p*r*t*1.0)/100 << endl;
	cout << "simple interest = " << (p*r*t*1.0)/100.0 << endl;
	cout << "simple interest = " << si << endl;

	// explicit type-casting

	cout << "simple interest = " << p*r*t/(float)100 << endl;
	cout << "simple interest = " << p*r*t/float(100) << endl;
	cout << "simple interest = " << ((float)p*r*t)/100 << endl;
	cout << "simple interest = " << (float(p)*r*t)/100 << endl;
	
	return 0;
}