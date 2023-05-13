#include<iostream>

using namespace std;

void increment(int a) {
	cout << "inside increment() : before ++ a = " << a << endl;
	a++;
	cout << "inside increment() : after ++ a = " << a << endl;
}

int main() {

	int a = 100;

	increment(a);

	cout << a << endl;

	return 0;
}