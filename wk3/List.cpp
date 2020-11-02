#include <iostream>
#include "List.h" 
using namespace std;

List::List(){ size = 0;}

List::~List(){

  Node *current = firstNode;
  while(current->next){ 
    Node *tmp = current;
    current = current->next;
    delete tmp;
  }

}

bool List::add(ItemType item){ 
  bool success = size < INT_MAX;
  if(success){ 
    Node *node = new Node;
    node->item = item;
    node->next = NULL;
    if (size == 0){ 
      firstNode = node;
    }
    else{ 
      Node *current = firstNode;
      while(current->next){ 
        current = current->next;
      }
      current->next = node;
    }
    size++;
  }
  return success;
}

bool List::add(int index , ItemType item){
  bool success = index >= 0 && index <= size;
  if(success){
    Node *node = new Node;
    node->item = item;
    node->next = NULL;
    if(index == 0){ 
      Node *tmp = firstNode;
      node->next = tmp;
      firstNode = node;
    }else{ 
      Node *current = firstNode;
      for(int i = 0; i < index - 1; i++){ 
        current = current->next;
      }
      node->next = current->next;
      current->next = node;
    }
    size++;
  }
  return success;
}

void List::remove(int index){ 
  bool success = index >= 0 && index <= size;
  if(success){
    Node *current = firstNode;
    if(index == 0){
      firstNode = current->next;
    }else{ 
      for(int i = 0; i < index - 1; i++){ 
        current = current->next;
      }
      //selects deleted node
      Node *tmp = current->next;
      current->next = current->next->next;
      delete tmp;//deletes it
    }
    size--;
  }
}

ItemType List::get(int index){ 
  Node *current = firstNode;
  for(int i=0; i<index; i++){
    current = current->next;
  }
  return current->item;
}

bool List::isEmpty(){ return (firstNode->next == NULL);}

int List::getLength(){return size;}

void List::print(){
  Node* current = firstNode;
  for(int i = 0; i < size; i++){
    cout << current->item << endl;
    current = current->next;
  }
}
