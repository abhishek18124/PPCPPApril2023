#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int lsf = INT_MIN; // to track the "largest so far"

	int i = 1;

	while(i <= n) {
		
		// 1. read an integer from user

		int x;
		cin >> x;

		// 2. compare that integer with lsf

		if(x > lsf) {
			lsf = x;
		}

		i = i+1;
	}

	cout << "largest = " << lsf << endl;
	
	return 0;
}