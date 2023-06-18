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

	customer(char* n, int a, char g, double c) {
		cout << "\nI am inside the parameterised constructor of the customer class\n";
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
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

	customer c1("naruto", 32, 'M', 5000);

	c1.printCustomerInfo();

	customer c2("sakura", 20, 'F', 1000);

	c2.printCustomerInfo();

	customer c3;

	return 0;
}