/*********************************************************************
 * ** Program Filename: list.h
 * ** Author: Max Franz
 * ** Date: 6/9/19
 * ** Description: This is the header file for the linked list node and linked list classes
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Linked_List_Node {
	public:
		int val; // the value that this node stores
        	Linked_List_Node *next; // a pointer to the next node in the list

		/*********************************************************************
		 * ** Function: Linked_List_Node(const Linked_List_Node&)
		 * ** Description: copy constructor
		 * ** Parameters: const Linked_List_Node&
		 * ** Pre-Conditions: object created with object in parameter field
		 * ** Post-Conditions: object created correctly
		 * *********************************************************************/
		Linked_List_Node(const Linked_List_Node&);
		/*********************************************************************
		 * ** Function: Linked_List_Node& operator=(const Linked_List_Node&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Linked_List_Node&
		 * ** Pre-Conditions: object assigned to object of same class type
		 * ** Post-Conditions: object successfully copied
		 * *********************************************************************/
		Linked_List_Node& operator=(const Linked_List_Node&);
		/*********************************************************************
		 * ** Function: Linked_List_Node()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object created
		 * ** Post-Conditions: created successfully
		 * *********************************************************************/
		Linked_List_Node();
		/*********************************************************************
		 * ** Function: ~Linked_List_Node()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope and deleted
		 * ** Post-Conditions: success
		 * *********************************************************************/
		~Linked_List_Node();
};

class Linked_List {
	private:
		unsigned int length; // the number of nodes contained in the list
        	Linked_List_Node *first; // a pointer to the first node in the list
	public:
		/*********************************************************************
		 * ** Function: int get_length()
		 * ** Description: gets length of current linked list (num. of nodes)
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: length returned
		 * *********************************************************************/
		int get_length();
		/*********************************************************************
		 * ** Function: void print()
		 * ** Description: prints the values of all nodes
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: node values printed
		 * *********************************************************************/
		void print(); // output a list of all integers contained within the list
		/*********************************************************************
		 * ** Function: void clear()
		 * ** Description: clears the entire linked list and sets length to 0
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: nodes deleted
		 * *********************************************************************/
	        void clear(); // delete the entire list (remove all nodes and reset length to 0)
		/*********************************************************************
		 * ** Function: unsigned int push_front(int)
		 * ** Description: adds a node to the front of the linked list
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: node added
		 * *********************************************************************/
	        unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
		/*********************************************************************
		 * ** Function: unsigned int push_back(int)
		 * ** Description: adds a node to the back of the linked list
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: node added
		 * *********************************************************************/
	        unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
		/*********************************************************************
		 * ** Function: unsigned int insert(int value, unsigned int index)
		 * ** Description: inserts a node at the specified index
		 * ** Parameters: int value, unsigned int index
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: node inserted
		 * *********************************************************************/
	        unsigned int insert(int value, unsigned int index);//insert a new value in the list at the specified index(returns the new length of the list)
		/*********************************************************************
		 * ** Function: void sort_ascending()
		 * ** Description: sorts nodes in ascending order by value
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: sorted in ascending order
		 * *********************************************************************/
	        void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	        // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
		// /*********************************************************************
		// ** Function: void sort_descending()
		// ** Description: sorts nodes in descending order by value
		// ** Parameters: N/a
		// ** Pre-Conditions: called
		// ** Post-Conditions: sorted in descending order
		// *********************************************************************/
	        void sort_descending(); // sort the nodes in descending order
		/*********************************************************************
		 * ** Function: Linked_List()
		 * ** Description: default constructor for linked list
		 * ** Parameters: N/a
		 * ** Pre-Conditions: list created
		 * ** Post-Conditions: success
		 * *********************************************************************/
		Linked_List();
		/*********************************************************************
		 * ** Function: ~Linked_List()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: memory deleted
		 * *********************************************************************/
		~Linked_List();
		/*********************************************************************
		 * ** Function: void MergeSort(Linked_List_Node**, char)
		 * ** Description: Main function for the merge sort, it calls all the other functions recursively and reconstructs the list when complete
		 * ** Parameters: Linked_List_Node**, char
		 * ** Pre-Conditions: This function is called after the user is done entering values
		 * ** Post-Conditions: Successfully sorts all nodes by value
		 * *********************************************************************/
		void MergeSort(Linked_List_Node**, char);
		/*********************************************************************
		 * ** Function: Linked_List_Node * SortedMerge(Linked_List_Node *a, Linked_List_Node *b, char)
		 * ** Description: This sorts the nodes by value in whichever order is decided by the user (ascending or descending)
		 * ** Parameters: Linked_List_Node *a, Linked_List_Node *b, char
		 * ** Pre-Conditions: This function is called when two nodes are passed to it
		 * ** Post-Conditions: Sorts each node based on value
		 * *********************************************************************/
		Linked_List_Node * SortedMerge(Linked_List_Node *a, Linked_List_Node *b, char);
		/*********************************************************************
		 * ** Function: void FrontBackSplit(Linked_List_Node *source, Linked_List_Node **frontRef, Linked_List_Node **backRef)
		 * ** Description: This splits the given list into two halves
		 * ** Parameters: Linked_List_Node *source, Linked_List_Node **frontRef, Linked_List_Node **backRef
		 * ** Pre-Conditions: The function is called if the given list is more than 0 or 1 items
		 * ** Post-Conditions: The list is split in to two halves
		 * *********************************************************************/
		void FrontBackSplit(Linked_List_Node *source, Linked_List_Node **frontRef, Linked_List_Node **backRef);
};

#endif
