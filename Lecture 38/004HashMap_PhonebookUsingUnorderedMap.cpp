/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Tanmay"].push_back("1234");
	phoneMap["Tanmay"].push_back("5678");
	phoneMap["Tanmay"].push_back("0011");

	phoneMap["Prakriti"].push_back("0000");
	phoneMap["Prakriti"].push_back("1111");

	phoneMap["Satvik"].push_back("9876");

	for (pair<string, vector<string>> contact : phoneMap) {
		string name = contact.first;
		vector<string> phoneNumbers = contact.second;
		cout << name << " : ";
		for (string phoneNum : phoneNumbers) {
			cout << phoneNum << " ";
		}
		cout << endl;
	}

	cout << endl;

	phoneMap["Tanmay"][0] = "5555";

	for (pair<string, vector<string>> contact : phoneMap) {
		string name = contact.first;
		vector<string> phoneNumbers = contact.second;
		cout << name << " : ";
		for (string phoneNum : phoneNumbers) {
			cout << phoneNum << " ";
		}
		cout << endl;
	}

	return 0;
}