#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(){};


Queue::~Queue(){
  bool success = !isEmpty();
  if(success){
    Node* temp = frontNode;
    while(temp){
      Node* curr = temp;
      curr->next = NULL; 
      delete curr;
      temp = temp->next;
    }
  }
};

bool Queue::isEmpty(){ 
  return frontNode == NULL || backNode == NULL;
}

bool Queue::enqueue(ItemType item){
  Node* newNode = new Node;
  newNode->item = item;
  newNode->next = NULL;
  if (isEmpty()){
    frontNode = newNode;
  }else{
    backNode->next = newNode;
  }
  backNode = newNode;
  return true;
}

bool Queue::dequeue(){
  Node* temp = frontNode;
  if(frontNode == backNode){
    frontNode = NULL;
    backNode = NULL;
  }else{
    frontNode = temp->next;
  }
  temp->next = NULL;
  delete temp;
  return true;
}

bool Queue::dequeue(ItemType &item){
  Node* temp = frontNode;
  if(frontNode == backNode){
    frontNode = NULL;
    backNode = NULL;
  }else{
    frontNode = temp->next;
  }
  temp->next = NULL;
  item = temp->item;
  delete temp;
  return true;
}

void Queue::getFront(ItemType &item){
  if(!isEmpty()){
    item = frontNode->item;
  }
}

void Queue::displayItems(){
  Node* temp = frontNode;
  while(temp){
    cout << temp->item << endl;
    temp = temp->next;
  }
}
