#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

ListNode* getNode(ListNode* temp, int j) {

	// this fn returns the address of the node at the jth index

	int k = 0;
	while (k < j and temp != NULL) {
		temp = temp->next;
		k++;
	}

	return temp;

}

// time : O(n) due to getNode()

void insertAtIndex(ListNode*& head, int val, int i) {

	if (i == 0) {
		insertAtHead(head, val);
		return;
	}

	ListNode* n = new ListNode(val);
	ListNode* prev = getNode(head, i - 1);

	if (prev == NULL) {
		// i > n (invalid index)
		return;
	}

	n->next = prev->next;
	prev->next = n;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	insertAtIndex(head, 25, 2);

	printLinkedList(head);

	insertAtIndex(head, 0, 0);

	printLinkedList(head);

	insertAtIndex(head, 35, 10);

	printLinkedList(head);

	return 0;
}