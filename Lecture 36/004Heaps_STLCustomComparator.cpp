/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {

public :

	string name;
	int age;
	float balance;

	customer(string name, int age, float balance) {
		this->name = name;
		this->age = age;
		this->balance = balance;
	}

};

class myAgeComparator {

public :

	// return true when swap is needed

	// return false when swap is not needed

	bool operator()(customer a, customer b) {
		if (b.age < a.age) {
			// we need to swap to buid a minHeap based on age
			return true;
		}
		// we don't need to swap to buid a minHeap based on age
		return false;
	}

};

class myBalanceComparator {

public :

	// return true when swap is needed

	// return false when swap is not needed

	// 'b' is the newly inserted node and 'a' is its parent

	bool operator()(customer a, customer b) {
		if (b.balance > a.balance) {
			// we need to swap to buid a maxHeap based on balance
			return true;
		}
		// we dont' need to swap to buid a maxHeap based on balance
		return false;
	}

};

int main() {

	priority_queue<customer, vector<customer>, myBalanceComparator> m;

	m.push(customer("dhairya", 18, 1000));
	m.push(customer("sarthak", 16, 600));
	m.push(customer("sanyam", 21, 1200));
	m.push(customer("mehakpreet", 17, 2000));
	m.push(customer("riya", 19, 1500));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << " " << c.balance << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}