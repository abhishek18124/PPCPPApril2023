#include<iostream>

using namespace std;

int main() {

	int* ptr = new int;

	*ptr = 20;

	cout << "*ptr = " << *ptr << endl;

	return 0;
}