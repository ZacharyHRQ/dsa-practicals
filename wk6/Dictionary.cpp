#include <iostream>
#include "Dictionary.h" 
using namespace std;

Dictionary::Dictionary(){
  for(int i = 0; i < MAX_SIZE; i++){
    items[i] = NULL;
  }
}

Dictionary::~Dictionary(){}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int) 'A';
		else
			return (int)c - (int) 'a' + 26;
	}
	else
		return -1;
}


int Dictionary::hash(KeyType key){ 
    int total = 0;
    for(char k : key){ 
      total += charvalue(k);
    }
    return total%MAX_SIZE;
}

bool Dictionary::add(KeyType newKey, ItemType newItem){  
  int index = hash(newKey);
  Node* curr = items[index];
  if (items[index] == NULL){ 
    Node *newNode = new Node;
    newNode->item = newItem;
    newNode->key = newKey;
    newNode->next = NULL;
    items[index] = newNode;
  }
  else{
    if (curr->key == newKey){
      return false;
    }
    while(curr){
      curr = curr->next;
      if (curr->key== newKey){ 
        return false;
      }
    }
    Node *newNode = new Node;
    newNode->item = newItem;
    newNode->key = newKey;
    newNode->next = NULL;
    curr = newNode;
  }
  size++;
  return true;
}

void Dictionary::remove(KeyType key){
  int index = hash(key);
  Node *curr = items[index]; 
  if(items[index] != NULL){
    Node* prev;
    while(curr->key != key){ 
      prev = curr;
      curr = curr->next;
    }
    Node* tmp = curr; 
    prev->next = curr->next;
    tmp->next = NULL;
    delete tmp;
  }
  size--;
}

ItemType Dictionary::get(KeyType key){
  int index = hash(key);
  Node *curr = items[index];
  if(!curr){
    return "";
  }else{
    Node *tmp = curr;
    while(tmp){
      if(tmp->key == key)return tmp->item;
      tmp = tmp->next;
    }
  }

  return "";
}



int Dictionary::getLength(){return size;}

void Dictionary::print(){ 
  for (int i = 0; i < MAX_SIZE ; i++)
    {
        Node* curr = items[i];
        if(curr){
            cout << curr->key << " :" << curr->item << endl;

            while(curr->next){
                cout << curr->next->key << " :" << curr->next->item << endl;
                curr = curr->next;
            }
        }

    }
}

bool Dictionary::isEmpty(){return bool(size);}
