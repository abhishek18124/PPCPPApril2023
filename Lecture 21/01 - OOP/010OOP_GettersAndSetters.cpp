#include<iostream>

using namespace std;

class customer {


	char name[100];
	int age;
	char gender;
	double credits;


public :




	customer() {
		cout << "I am inside the default constructor" << endl;
	}

	customer(char* n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		strcpy(name, n);
		age = a;
		gender = g;
		credits = c;
	}

	void setAge(int a) {
		age = a;
	}

	int getAge() {
		return age;
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

	customer c("sakura", 20, 'F', 1000);

	// cout << c.age << endl;

	// c.age = 25;

	// cout << c.age << endl;

	cout << c.getAge() << endl;

	c.setAge(25);

	cout << c.getAge() << endl;

	return 0;
}