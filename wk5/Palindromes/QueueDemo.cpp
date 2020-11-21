#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;
int main(){
  Queue q = Queue();
  q.enqueue('a');
  q.enqueue('b');
  char item;
  q.getFront(item);
  cout << item << endl; 
  q.displayItems();
  q.dequeue();
  q.displayItems();
  


  //improvement

  Queue wordqueue = Queue();
  Stack s = Stack();
  string word; 
  cin >> word;
  for(char c : word){ 
    char w = c;
    s.push(w);
    wordqueue.enqueue(w);
  }
  bool success;
  char w,k;
  s.pop(w);
  wordqueue.dequeue(k);
  while(w || k){
    if(w != k){
      success = false;
    }
    s.pop(w);
    wordqueue.dequeue(k);
  }
  if(success){ 
    cout << "The word u enetered is a palindrome" << endl;
  }else{
    cout << "The word u enetered is not a palindrome" << endl;
  }
}

