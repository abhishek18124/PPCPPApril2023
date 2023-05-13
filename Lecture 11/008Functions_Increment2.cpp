#include<iostream>

using namespace std;

void incr(int& b) {
	b++;
}

int main() {

	int a = 10;

	incr(a);

	cout << a << endl;
	
	return 0;
}