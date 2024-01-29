#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	int* ptr = (int*)&ch;
	cout << ptr << endl;

	return 0;
}