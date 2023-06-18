#include<iostream>

using namespace std;

class customer {
public :
	char name[100];
	int age;
	char gender;
	double credits;

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	customer(customer& c) {
		cout << "I am inside the copy constructor of the customer class" << endl;
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

};

int main() {

	customer c1("naruto", 32, 'M', 5000); // parameterised constructor is invoked

	// customer c2 = c1; // copy constructor is invoked

	customer c2(c1); // copy constructor is invoked

	c2.printCustomerInfo();

	return 0;
}