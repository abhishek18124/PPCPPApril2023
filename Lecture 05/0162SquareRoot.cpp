#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cin >> p;

	double sqrt = 0;
	double increment_factor = 1;

	int i = 1;
	while(i <= p+1) {
		
		while(sqrt*sqrt <= n) {
			sqrt = sqrt+increment_factor;
		}
		sqrt = sqrt-increment_factor;

		i = i+1;
		increment_factor = increment_factor/10;
	}

	cout << sqrt << endl;
	
	return 0;
}