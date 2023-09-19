#include<iostream>
#include<functional>

using namespace std;

class pairGenericHash {

public :

	template <typename T1, typename T2>
	size_t operator()(const pair<T1, T2>& p) const {

		hash<T1> hasher1;
		hash<T2> hasher2;

		auto hash1 = hasher1(p.first);
		auto hash2 = hasher2(p.second);

		return hash1 ^ hash2;

	}

};

class pairIntegerHash {

public :


	size_t operator()(const pair<int, int>& p) const {

		hash<int> integerHasher;

		auto hash1 = integerHasher(p.first);
		auto hash2 = integerHasher(p.second);

		return hash1 ^ hash2;

	}

};


int main() {

	hash<string> stringHasher;

	cout << stringHasher("coding") << endl;

	hash<float> floatHasher;

	cout << floatHasher(3.14) << endl;

	hash<int> integerHasher;

	cout << integerHasher(40) << endl;

	hash<double> doubleHasher;

	cout << doubleHasher(1.2345) << endl;

	pairIntegerHash pairHasher;

	cout << pairHasher(make_pair(1, 2)) << endl;

	cout << (integerHasher(1) ^ integerHasher(2)) << endl;

	pairGenericHash pGHasher;

	cout << pGHasher(make_pair("abc", "def")) << endl;


	return 0;
}