#include<iostream>

using namespace std;

class customer {
public :
	char* name; // it is allocated memory on the heap
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

	void printCustomerInfo() {
		cout << "\nCustomer Information\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl;
	}

	~customer() {
		delete [] name;
		cout << "destructing " << name << endl;
	}

};

int main() {

	customer c1("naruto", 32, 'M', 5000);
	customer c2("sakura", 30, 'F', 1000);

	return 0;
}