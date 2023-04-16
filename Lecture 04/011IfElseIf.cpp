#include<iostream>

using namespace std;

int main() {

	// int marks;

	// cout << "enter your marks : ";
	// cin >> marks;

	// if(marks >= 91 and marks <= 100) {
	// 	cout << "grade A" << endl;
	// } else if(marks >= 81 and marks <= 90) {
	// 	cout << "grade B" << endl;
	// } else if(marks >= 71 and marks <= 80) {
	// 	cout << "grade C" << endl;
	// } else if(marks >= 61 and marks <= 70) {
	// 	cout << "grade D" << endl;
	// } else {
	// 	cout << "grade F" << endl;
	// }

	// cout << "you are outside the if-else-if block" << endl;

	char grade;

	cout << "enter your grade  : ";
	cin >> grade;

	switch(grade) {
		case 'A' : cout << "very good" << endl; break;
		case 'B' : cout << "good" << endl; break;
		case 'C' : cout << "average" << endl; break;
		case 'D' : cout << "bad" << endl; break;
		case 'F' : cout << "very bad" << endl; break;
		default  : cout << "invalid grade" << endl; break; 
	}
	
	return 0;
}