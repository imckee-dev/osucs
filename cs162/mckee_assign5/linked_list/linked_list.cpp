/*********************************************************************
** Program Filename: linked_list.cpp
** Author: Ian McKee + Skeleton code creator (Alex or Roger probably)
** Date: 12/8/2023
** Description: Defines all of our linked list functions in that were declared in linked_list.h
** Input: We need the Node's class definition in here (gathered from node.h)
** Output: The Linked List class
*********************************************************************/

#include "linked_list.h"

Linked_List::Linked_List() {
	length = 0;
	head = nullptr;
}

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	// Your code goes here:

	return length;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	// Your code goes here:
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->next != nullptr) {
			cout << temp->val << " ";
		} else {
			cout << temp->val;
		}
		temp = temp->next;
	}
	cout << "\n";

	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	// Your code goes here:
	Node* temp = head;//first point, set temp to the pointer to the second item

	while (head != nullptr) { //while the head next pointer isnt null (we're not at the last point)
		pop_front();
	}

	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list 
	// Your code goes here:
	Node* newNode = new Node;
	newNode->val = val;
	newNode->next = head;
	head = newNode;

	length++; //increment the lengtht o make it accurate

	return;
}

void Linked_List::push_back(int val){
	// insert a new value at the back of the list 
	// Your code goes here:
	Node* newNode = new Node;
	newNode->val = val;
	newNode->next = nullptr;
	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head; //create a temporary node to traverse the list with the head pointer.
		while (temp->next != nullptr) { //while the temporary's next pointer is not null (i.e. we're not at the end position)
			temp = temp->next; //go through the linked list (This new Node pointer goes to the next pointer within it)
		}//after the two we are now at temp = the end
		temp->next = newNode;
	}

	
	length++;


	return;
}

void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	// Your code goes here:
	if (index > length) return; //exhaust anything greater than our length
	if (index == 0) {
		push_front(val);
		return;
	} //at the start?

	Node* newNode = new Node;//make our new node with the value
	newNode->val = val;

	//traverse to the index:
	Node* temp = head; //start at index 0
	for (int i = 0; i < index - 1; i++) { //0, 1, 2,  for index 3 length 5
		temp = temp->next;
	}//temp is at the node before new node
	
	newNode->next = temp->next; //newnode also points to this current value's next node

	temp->next = newNode; //now this temp one is set to the newnode itself so now its temp->newnode->newnodenext

	


	length++; //increment lengthand return
	return;
}

void Linked_List::pop_back(){
	// remove the node at the back of the list
	// Your code goes here:
	if (head == NULL) {
		return; //exhausts the empty list possibility
	}
	if (head->next == nullptr) {
		delete head; 
		head = nullptr;
		length--;
		return; //exhausts the 1 list possibility
	}
//for two or more:
	Node* temp = head; //create a temporary node to traverse the list with the head pointer.
	while (temp->next != nullptr && temp->next->next != nullptr) { //while the temporary's next pointer is not null (i.e. we're not at the end or 2nd to end.)
		temp = temp->next; //go through the linked list (This new Node pointer goes to the next pointer within it)
	}//after the two we are now at temp = 2 before the end
	delete temp->next;
	temp->next = nullptr;


	
	length--;
	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	// Your code goes here:
	if (head == nullptr) {
		return; //if the list is empty:
	}

	Node* temp = head->next; //set temporary variable to the second index

	delete head;

	head = temp; 

	length--;

	return;
}

void Linked_List::remove(int index){
	// remove the node at index of the list
	// Your code goes here:
	if (index >= length) return; //exhaust anything greater than or equal to our length (out of bounds)
	if (index == 0) {
		pop_front();//pop the front if we're given the beginning
		return;
	} //at the start?

	if (index == length - 1) {
		pop_back();//pop the back if we're given the length
		return;
	} //at the start?

	// Node* newNode = new Node;//make our new node with the value no new node.
	// newNode->val = val;

	//traverse to the index:
	Node* temp = head; //start at index 0
	for (int i = 0; i < index - 1; i++) { //0, 1, 2,  for index 3 length 5
		temp = temp->next;
	}//temp is at the node before node to remove
	
	// if (temp->next == nullptr) {//if we got to the end of the list
	// 	pop_back();
	// 	return;
	// }

	Node* temp2 = temp->next->next; //copy the next next one

	delete temp->next;

	temp->next = temp2;
	


	length--; //increment lengthand return


	return;
}

void Linked_List::merge_split(Node*& head1, Node*& head2, int length) {
	if (length < 2) return;
	for (int i = 0; i < length/2 - 1 && head1 != nullptr && head2 != nullptr; i++) {
		//merge the two lists into our new list of size n
		head2 = head2->next; //get to our middle index
	}

    Node* temp = head2->next; //set temp one to our middle index
    head2->next = nullptr; //head2 next one is now null
    head2 = temp; //splits our list into two here

	if (head2->val >= head1->val) {
		push_back(head2->val);
	} 
}

void Linked_List::merge_split_back(Node*& head1, Node*& head2, int length) {
	if (length < 2) return;
	for (int i = 0; i < length/2 - 1 && head1 != nullptr && head2 != nullptr; i++) {
		//merge the two lists into our new list of size n
		head2 = head2->next; //get to our middle index
	}

    Node* temp = head2->next; //set temp one to our middle index
    head2->next = nullptr; //head2 next one is now null
    head2 = temp; //splits our list into two here

	if (head2->val <= head1->val) {
		push_back(head2->val);
	} 
}

Node* Linked_List::merge(Node* head1, Node* head2) {
    Node* head = nullptr;
    if (head1 == nullptr) {
        return head2;
    } else if (head2 == nullptr) {
        return head1;
    }

    if (head1->val <= head2->val) {
        head = head1;
        head->next = merge(head1->next, head2);
    } else {
        head = head2;
        head->next = merge(head1, head2->next);
    }

    return head;
}

void Linked_List::merge_sort(Node*& head, int length) {
	if (head == nullptr || head->next == nullptr) {	//base case: list has length 1, return. Do nothing.
		return;
	}
	Node* head1 = head;
	Node* head2 = head; //temporary to iterate to middle

	merge_split(head1, head2, length);//splits it into a list

	merge_sort(head1, length/2);
	merge_sort(head2,length-length/2);//start here (in the middle)

	head = merge(head1, head2);

}

void Linked_List::merge_sort_desc(Node*& head, int length) {
	if (head == nullptr || head->next == nullptr) {	//base case: list has length 1, return. Do nothing.
		return;
	}
	Node* head1 = head;
	Node* head2 = head; //temporary to iterate to middle

	merge_split_back(head1, head2, length);//splits it into a list

	merge_sort_desc(head1, length/2);
	merge_sort_desc(head2,length-length/2);//start here (in the middle)

	head = merge(head1, head2);

}


void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	// Your code goes here:
	merge_sort(head,length);

	//three iterators: first list, second, and the new list
	//compare the first of each two and put whichever one to the new list

	return;
}

void Linked_List::sort_descending(){
	// sort the nodes in descending order
	// Your code goes here:

	merge_sort_desc(head,length);

	return;
}
