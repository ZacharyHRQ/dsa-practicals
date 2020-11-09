#include <iostream>
#include <vector>
#include "Stack.h" 
using namespace std;

Stack::Stack(){}

Stack::~Stack(){}

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

void Stack::displayInOrderOfInsertion(){
  vector<ItemType> items;
  Node *curr = topNode;
  while(curr){
    items.insert(items.begin(),curr->item);
    curr = curr->next;
  }
  for(auto& i:items){
    cout << i << ' ';
  }
}
