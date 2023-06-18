#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\nI am inside the default constructor of the customer class\n";
	}

	void printCustomerInfo() {
		cout << "\ncustomer information\n";
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
		cout << "gender : " << gender << endl;
		cout << "credits : " << credits << endl;
	}
};


int main() {

	customer c1; // object declaration

	strcpy(c1.name, "harsh");
	c1.age = 20;
	c1.gender = 'M';
	c1.credits = 1000;

	c1.printCustomerInfo();

	return 0;
}