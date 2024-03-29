#include<iostream>

using namespace std;

class ListNode {
public:

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

// time : n/2 steps ~ O(n)

ListNode* computeMidPoint(ListNode* head) {

	if (head == NULL) {
		// LL is empty
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {

		slow = slow->next;
		fast = fast->next->next;

	}

	return slow;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 60);
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);

	printLinkedList(head);

	ListNode* midPoint = computeMidPoint(head);

	midPoint != NULL ? cout << midPoint->val << endl : cout << "LL is empty" << endl;

	return 0;
}