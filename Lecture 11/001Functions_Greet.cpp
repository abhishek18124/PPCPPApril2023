#include<iostream>

using namespace std;

void greet() {
	cout << "inside greet() : hello world" << endl;
	return; // optional
}

int main() {

	cout << "inside main() : before greet()" << endl;

	greet();

	cout << "inside main() : after greet()" << endl;
	
	return 0;
}