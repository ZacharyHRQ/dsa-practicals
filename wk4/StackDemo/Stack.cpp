#include <iostream>
#include <vector>
#include "Stack.h" 
using namespace std;

Stack::Stack(){}

Stack::~Stack(){
  Node *curr = topNode;
  while(curr){ 
    Node *temp = curr;
    curr = curr->next;
    delete temp;
  }
}

bool Stack::isEmpty(){
  return topNode == NULL;
}

bool Stack::push(ItemType &item){
  Node *temp = topNode;
  Node *newNode = new Node;
  newNode->item = item;
  newNode->next = temp;
  topNode = newNode;
  return true;
}

bool Stack::pop(){
  bool success = !isEmpty();
  if(success){ 
    Node *temp = topNode;
    topNode = topNode->next;
    delete temp;
  }
  return success;
}

bool Stack::pop(ItemType &item){
  bool success = !isEmpty();
  if(success){ 
    Node *temp = topNode;
    topNode = topNode->next;
    item = temp->item;
    delete temp;
  }
  return success;
}

void Stack::getTop(ItemType &item){
  item = topNode->item;
}

void Stack::displayInOrder(){
  Node *curr = topNode;
  while(curr){
    cout << curr->item << endl;
    curr = curr->next;
  }
}

void Stack::reccur(Node* s){ 
  if(s == NULL) return; 
  reccur(s->next); 
  cout << s->item << " ";
}

void Stack::displayInOrderOfInsertion(){
  Node *curr = topNode; 
  reccur(curr);
  cout << endl;
}

