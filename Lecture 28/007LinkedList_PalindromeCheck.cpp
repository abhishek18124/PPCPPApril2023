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

ListNode* reverseIterative(ListNode* head) {

	ListNode* cur = head;
	ListNode* prev = NULL;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;
}

ListNode* getMidPoint(ListNode* head) {
	if (head == NULL) {
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

// steps = 3n/2 ~ O(n)

bool isPalindrome(ListNode* head1) {

	// 1. divide the LL around the midPoint

	ListNode* midPoint = getMidPoint(head1); // n/2 steps
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	// 2. reverse the second subList i.e. head2

	head2 = reverseIterative(head2); // n/2 steps

	// 3. comparision // n/2 steps

	while (head2 != NULL) {
		if (head1->val != head2->val) {
			// LL is not a palindrome
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}

	// LL is a palindrome
	return true;

}

int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	isPalindrome(head) ? cout << "palindrome" << endl : cout << "not a palindrome" << endl;

	return 0;
}