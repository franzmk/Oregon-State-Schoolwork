/*********************************************************************
 * ** Program Filename: list.cpp
 * ** Author: Max Franz
 * ** Date: 6/9/19
 * ** Description: This is the driver file for the linked list header file
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "list.h"

Linked_List_Node::Linked_List_Node() {
	val = 0;
	next = NULL;
}

Linked_List_Node::Linked_List_Node(const Linked_List_Node &old) {
	val = old.val;
	next = old.next;
}

Linked_List_Node& Linked_List_Node::operator=(const Linked_List_Node &old) {
	if(this != &old) {
		val = old.val;

		next = old.next;
	}
	return *this;
}

Linked_List_Node::~Linked_List_Node() {
	if(next != NULL) {
		delete next;
		next = NULL;
	}
}

Linked_List::Linked_List() {
	length = 0;
	first = NULL;
}

int Linked_List::get_length() {
	return length;
}

void Linked_List::print() {
	int num_prime = 0;
	Linked_List_Node *temp = first;
	cout << "Values: ";
	for(unsigned int i = 0; i < length; i++) {
		cout << temp->val << " ";
		
		int count = 0;
		for(int j = 2; j < temp->val; j++) if(temp->val % j == 0) count++;
		if(count <= 1) num_prime += 1;

		if(temp->next != NULL) temp = temp->next;
	}

	cout << endl;
	cout << "Number of prime numbers: " << num_prime << endl;
}

void Linked_List::clear() {
	if(first != NULL) {
		delete first;
		first = NULL;
	}
	length = 0;
}

unsigned int Linked_List::push_front(int value) {
	if(first == NULL) {
		first = new Linked_List_Node();
		first->val = value;
		length += 1;
	}
	else {
		Linked_List_Node *temp = new Linked_List_Node();

		temp->val = value;
		temp->next = first;

		first = temp;

		length += 1;
	}
	return length;
}

unsigned int Linked_List::push_back(int value) {
	if(first == NULL) {
		first = new Linked_List_Node();
		first->val = value;
		length += 1;
	}
	else {
		Linked_List_Node *temp = first;
		for(unsigned int i = 0; i < length; i++) {
			if(temp->next == NULL) {
				temp->next = new Linked_List_Node();
				temp->next->val = value;
				length += 1;
			}
			else temp = temp->next;
		}
	}
	return length;
}

unsigned int Linked_List::insert(int value, unsigned int index) {
	Linked_List_Node *temp = first;
	for(unsigned int i = 0; i < index; i++) {
		if(i == index-1) {
			Linked_List_Node *insert = new Linked_List_Node();

			insert->val = value;
			insert->next = temp->next;

			temp->next = insert;
			length += 1;
		}
		else temp = temp->next;
	}
	return length;
}

void Linked_List::MergeSort(Linked_List_Node** headRef, char a_or_d) { 
	Linked_List_Node *head = *headRef; 
	Linked_List_Node *a, *b; 

	if ((head == NULL) || (head->next == NULL)) return; 

	FrontBackSplit(head, &a, &b); 

	MergeSort(&a, a_or_d); 
	MergeSort(&b, a_or_d); 

	*headRef = SortedMerge(a, b, a_or_d); 
} 

Linked_List_Node * Linked_List::SortedMerge(Linked_List_Node *a, Linked_List_Node *b, char a_or_d) { 
	Linked_List_Node* result = NULL; 

	if (a == NULL) return b; 
	else if (b == NULL) return a; 

	if(a_or_d == 'a') {
		if(a->val <= b->val) { 
			result = a; 
			result->next = SortedMerge(a->next, b, a_or_d); 
		} 
		else { 
			result = b; 
			result->next = SortedMerge(a, b->next, a_or_d); 
		}
	}
	else if(a_or_d == 'd') {
		if(a->val >= b->val) {
			result = a;
			result->next = SortedMerge(a->next, b, a_or_d);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next, a_or_d);
		}
	}
	return result; 
} 

void Linked_List::FrontBackSplit(Linked_List_Node *source, Linked_List_Node **frontRef, Linked_List_Node **backRef) { 
	Linked_List_Node *fast, *slow; 
	slow = source; 
	fast = source->next; 

	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 

void Linked_List::sort_ascending() {
	MergeSort(&first, 'a');
}

void Linked_List::sort_descending() {
	MergeSort(&first, 'd');
}

Linked_List::~Linked_List() {
	clear();
}
