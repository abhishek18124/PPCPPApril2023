#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

/*
	return 'true' when a swap isn't required.

*/

bool myAgeComparator(customer a, customer b) {
	if (a.age < b.age) {
		// you don't need a swap to sort the vector<int> in inc. order
		return true;
	}

	// you need a swap
	return false;
}

bool myCreditCompartor(customer a, customer b) {
	if (a.credits > b.credits) {
		// you don't need a swap to sort the vector<int> in dec. order of credits
		return true;
	}

	// you need a swap
	return false;
}

int main() {

	vector<customer> v;

	v.push_back(customer("dhairya", 19, 'M', 500));
	v.push_back(customer("satvik", 18, 'M', 1000));
	v.push_back(customer("jatish", 20, 'M', 250));
	v.push_back(customer("prakriti", 17, 'F', 750));
	v.push_back(customer("abhishek", 16, 'M', 1200));

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), myAgeComparator);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), myCreditCompartor);


	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.credits << endl;
	}

	cout << endl;

	return 0;
}