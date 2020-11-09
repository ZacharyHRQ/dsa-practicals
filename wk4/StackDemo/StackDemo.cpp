#include <iostream>
#include "Stack.h"
using namespace std;
int main(){
  Stack s = Stack();
  int k = 3 , j = 4;
  s.push(k);
  s.push(j);
  int topValue;
  s.getTop(topValue);
  cout << topValue << endl;
  s.displayInOrderOfInsertion();
  cout << endl; 
  s.pop();
  s.displayInOrderOfInsertion();
}

