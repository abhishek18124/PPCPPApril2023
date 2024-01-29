#include<iostream>

using namespace std;

class customer {
public :
	char* name;
	int age;
	char gender;
	double credits;

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		name = new char[100];
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	customer(customer& c) {
		cout << "I am inside the copy constructor of the customer class" << endl;
		name = new char[100];
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

	customer c1("naruto", 32, 'M', 5000);

	c1.printCustomerInfo();

	customer c2 = c1;

	strcpy(c2.name, "sasuke");

	cout << c1.name << " " << c2.name << endl;

	c2.age = 40;

	cout << c1.age << " " << c2.age << endl;

	return 0;
}