#include<iostream>
#include<unordered_map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	unordered_map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;

public :

	trie() {
		root = new node('#');
	}

	// time ~ length of the string

	void insert(string str) {
		node* curr = root;
		for (char ch : str) {
			if (curr->childMap.find(ch) == curr->childMap.end()) {
				node* n = new node(ch);
				curr->childMap[ch] = n;
			}
			curr = curr->childMap[ch];
			curr->freq++;
		}
		curr->terminal = true;
	}

	// time ~ length of the string

	bool search(string str) {
		node* curr = root;
		for (char ch : str) {
			if (curr->childMap.find(ch) == curr->childMap.end()) {
				return false;
			}
			curr = curr->childMap[ch];
		}
		return curr->terminal;
	}

	// time ~ length of the word

	string uniquePrefix(string word) {

		node* curr = root;
		string prefix = "";

		for (char ch : word) {
			curr = curr->childMap[ch];
			prefix += ch;
			if (curr->freq == 1) {
				return prefix;
			}
		}

		return "";


	}
};


int main() {

	string words[] = {"code", "coder", "coding", "new", "neon", "next"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << word << " : " << t.uniquePrefix(word) << endl;
	}

	return 0;
}