// List.cpp - Implementation of List ADT using Pointers (Linked-implementation

#include "List.h"	// firstNodeer file
#include <cstddef>  // for NULL
#include <new>      // for bad_alloc
#include <set>      // for bad_alloc

// constructor
List::List()
{
	firstNode = NULL;
	size = 0;
}

// add a new item to the back of the list (append)
bool List::add(ItemType newItem)
{
	// create a new node to store the data item
	Node* newNode = new Node;
	newNode->item = newItem;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* temp = firstNode;
		while (temp->next != NULL)
			temp = temp->next;		// move to last node
		temp->next = newNode;		// make last node point to the new node
	}

	size++;

	return true;  // no size constraint
}

// add a new item at a specified position in the list (insert)
bool List::add(int index, ItemType newItem)
{
	bool success = (index >= 0) && (index <= size);

	if (success)
	{
		// create a new node to store the data item
		Node* newNode = new Node;
		newNode->item = newItem;
		newNode->next = NULL;

		if (index == 0) // inserting in front
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* temp = firstNode;
			for (int i = 1; i < index - 1; i++)
				temp = temp->next;		// move to node at the position before the index

			newNode->next = temp->next;	// make new node point to the node pointed to by temp
			temp->next = newNode;		// make temp point to the new node
		}
		size++;
	}

	return success;
}

// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index <= size - 1) && (size != 0);
	if (success)
	{
		Node* tmp = firstNode;
		if (index == 0) // remove front node
			firstNode = firstNode->next;
		else
		{
			Node* current = firstNode;
			Node* previous = firstNode;
			for (int i = 1; i < index; i++)
			{
				previous = current;
				current = current->next;		// move to next node
			}

			previous->next = current->next;	// delete the current node by
		}		                                // making previous node point to the node pointed to by current node
		delete tmp;
		tmp = NULL;
		size--;  // decrease the size of the list by one
	}
}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{
	ItemType dataItem = -1;
	bool success = (index >= 0) && (index <= size - 1);
	if (success)
	{
		Node* current = firstNode;
		for (int i = 1; i < index; i++)
			current = current->next;		// move to next node

		dataItem = current->item;
	}

	return dataItem;
}

// check if the list is empty
bool List::isEmpty()
{
	return size == 0;
}

// check the size of the list
int List::getLength()
{
	return size;
}

//------------------- Other useful functions -----------------
void List::print()
{
	Node* temp = firstNode;

	if (temp == NULL)
		cout << "The list is empty." << endl;
	else
	{
		while (temp != NULL)
		{
			cout << temp->item << "\t";
			temp = temp->next;		// move to next node
		}
	}
}


void List::sortedInsert(ItemType item)
{
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;
    Node* curr = firstNode;
    while(curr->next && item >= curr->next->item ){
      curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}


List::Node* List::sortedMerge(Node*& a, Node*& b)
{
	//to be implemented
  Node* mergedList = new Node;
  Node* curr = mergedList;
  while(a->next != NULL && b->next != NULL){
    Node* newNode = new Node;
    if(a->item < b->item){
      newNode->item = a->item;
      newNode->next = NULL;
      curr->next = newNode;
      a = a->next;
    }
    else{
      newNode->item = b->item;
      newNode->next = NULL;
      curr->next = newNode;
      b = b->next;
    }
  }
  Node* left = (a!=nullptr) ? a : b;
  curr->next = left;
  return mergedList;
}

int List::count(ItemType item){
  int count = 0;
  Node* curr = firstNode;
  while(curr->next){
    if (curr->item == item) count ++;
    curr = curr->next;
  }
  return count;
}

int List::Rcount(Node* temp , ItemType item){ 
  if(temp == NULL) return 0;
  return (Rcount(temp->next,item) + ((temp->item == item)? 1:0));
}

int List::countR(ItemType item){
   
  return Rcount(firstNode,item);

}

void List::reverse(){
  Node* curr = firstNode;
  Node* prev  = NULL;
  Node* next = NULL;
  while(curr != NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  firstNode = prev;
}
 
void List::reverseR(){ 

  helperReverse(firstNode);
}

List::Node* List::helperReverse(Node* temp){ 
  if(temp == NULL) return NULL;
  if(temp->next == NULL) { 
    firstNode = temp;
    return temp;
  }
  Node* node = helperReverse(temp->next);
  node->next = temp;
  temp->next = NULL;
  return temp;
}

void List::removeDups(){ 
  Node* curr = firstNode;
  while(curr->next){ 
    while(curr->next && curr->item == curr->next->item){ 
      curr->next = curr->next->next;
    }
    curr = curr->next;
  }
}

void List::removeDupsUnsorted(){ 
  set<int> seen;
  Node* curr = firstNode;
  while(curr->next){
    if(curr->next->next && seen.find(curr->item) != seen.end()){ 
      curr->next = curr->next->next;
    }
    else{ 
      seen.insert(curr->item);
    }
    curr = curr->next;
  }
}

void List::reverseAt(int start, int end){
  Node* d = new Node;
  d->next = firstNode;
  Node* curr = firstNode , *prev = d;
  for(int i = 0; i<start-1; i++){ 
    curr = curr->next;
    prev = prev->next;
  }
  Node* temp = NULL; 
  for(int i =0; i < end-start+1; i++){
    Node* next = curr->next;
    curr->next = temp; 
    temp = curr; 
    curr = next;
  }
  prev->next->next = curr; 
  prev->next = temp; 

  firstNode = d->next; 
} 
