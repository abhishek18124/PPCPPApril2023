#include<iostream>
#include<cstring>

using namespace std;

void f() {
	static int i = 0;
	cout << i << " ";
	i++;
}

int main() {

	char str[] = "abc.def.ghi";
	char dlim[] = ".";

	// char* token = strtok(str, dlim);
	// cout << token << endl;

	// token = strtok(NULL, dlim);
	// cout << token << endl;

	// token = strtok(NULL, dlim);
	// cout << token << endl;

	char* token = strtok(str, dlim);

	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, dlim);
	}

	// f();
	// f();
	// f();

	return 0;
}