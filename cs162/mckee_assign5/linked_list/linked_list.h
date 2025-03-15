/*********************************************************************
** Program Filename: linked_list.h
** Author: Ian McKee + Skeleton code creator (Alex or Roger probably)
** Date: 12/8/2023
** Description: Header file for our linked_list.cpp, declares all of our to-be-defined functions to modify our linked list.
** Input: We need the Node's class definition in here (gathered from node.h)
** Output: The Linked List class
*********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include <iostream>

using namespace std;

class Linked_List {
private:
	int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list
	// anything else you need...
public:

	Linked_List();

/*********************************************************************
** Function: get_length
** Description: Returns our length of the linked list.
** Parameters: None
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: our length of the linked list.
*********************************************************************/
	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
   /*********************************************************************
** Function: print
** Description: Prints our elements of the linked list.
** Parameters: None
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Prints our elements of the linked list.
*********************************************************************/
	void print(); // output a list of all integers contained within the list

	   /*********************************************************************
** Function: clear
** Description: Clears our elements of the linked list.
** Parameters: None
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Empty linked list. With a head that leads to null.
*********************************************************************/
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
      /*********************************************************************
** Function: push_front()
** Description: Appends our new integer at the front of our defined linked list.
** Parameters: a new integer to add
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list with a new value at the start 
*********************************************************************/
	void push_front(int); // insert a new value at the front of the list 

	      /*********************************************************************
** Function: push_back()
** Description: Appends our new integer at the end of our defined linked list.
** Parameters: a new integer to add
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list with a new value at the end 
*********************************************************************/
	void push_back(int); // insert a new value at the back of the list 

	      /*********************************************************************
** Function: insert()
** Description: Appends our new integer at the given index of our defined linked list.
** Parameters: a new integer to add and an integer of the index.
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list with a new value at the given posotion. 
*********************************************************************/
	void insert(int val, int index); // insert a new value in the list at the specified index 

	      /*********************************************************************
** Function: pop_back()
** Description: Removes integeer at the end of our defined linked list.
** Parameters:none
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list without the last value, or nothing if the list is empty.
*********************************************************************/
	void pop_back(); // remove the node at the back of the list

		      /*********************************************************************
** Function: pop_front()
** Description: Removes integeer at the front of our defined linked list.
** Parameters:none
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list without the front value, or nothing if the list is empty.
*********************************************************************/
	void pop_front(); // remove the node at the front of the list

		      /*********************************************************************
** Function: remove()
** Description: Removes integeer at the oindex of our defined linked list.
** Parameters: index of the thing to be removed
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list without the given index, or nothing if the list is empty/index is greater han lenght
*********************************************************************/
	void remove(int index); // remove the node at index of the list

		      /*********************************************************************
** Function: merge_split() / back for descending
** Description: Will split our given linked list (helper function) for our merge sort function.
** Parameters: Passed in two node pointers that will be our first half and second half's heads.
** Pre-Conditions: A linked list has been defined, along with two node pointer variables.
** Post-Conditions: Same but modified lnk ed list without the given index, or nothing if the list is empty/index is greater han lenght
*********************************************************************/
	void merge_split(Node*& first, Node*& second, int length);
	void merge_split_back(Node*& first, Node*& second, int length);

		      /*********************************************************************
** Function: merge_sort()
** Description: Removes integeer at the oindex of our defined linked list.
** Parameters: Passed linked list by referecne and the number of items in it
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list without the given index, or nothing if the list is empty/index is greater han lenght
*********************************************************************/
	void merge_sort(Node*& head, int length);
	void merge_sort_desc(Node*& head, int length);

		      /*********************************************************************
** Function: merge()
** Description: Takes our two defined head1 and head2 and merges the lists together
** Parameters: Passed linked list by referecne and the number of items in it
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Same but modified lnk ed list without the given index, or nothing if the list is empty/index is greater han lenght
*********************************************************************/
	Node* merge(Node* head1, Node* head2);


		      /*********************************************************************
** Function: sprt_ascending()
** Description: Sorts the linked list from smallest to largest
** Parameters: None
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Returns the list in order from smallest to largest
*********************************************************************/
	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm

			      /*********************************************************************
** Function: sprt_descending()
** Description: Sorts the linked list from largest to smallest
** Parameters: None
** Pre-Conditions: A linked list has been defined.
** Post-Conditions: Returns the list in order from largest to smallest
*********************************************************************/
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	void sort_descending(); // sort the nodes in descending order

	// you can add extra member variables or functions as desired

};




#endif
