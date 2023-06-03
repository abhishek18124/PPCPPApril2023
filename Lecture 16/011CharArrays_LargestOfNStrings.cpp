// strlen <= 100

#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the no. of strings : ";
	cin >> n;

	// cin.ignore();
	cin.get();

	char inp[101];
	// cin >> inp;
	cin.getline(inp, 101); // by default '\n' is the delimiter

	char lsf[101];
	strcpy(lsf, inp);

	for (int i = 1; i <= n - 1; i++) {
		cout << ".";
		// cin >> inp;
		cin.getline(inp, 101); // by default '\n' is the delimiter
		if (strcmp(inp, lsf) > 0) {
			strcpy(lsf, inp);
		}
	}

	cout << lsf << endl;

	return 0;
}
