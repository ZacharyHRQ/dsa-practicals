#include <iostream>
#include "List.h"

using namespace std;
int main(){

  //a
  List linkedList = List();
  //b
  linkedList.add("Annie");
  //c
  linkedList.add("Jacky");
  //d
  linkedList.add("Wendy");
  //e
  linkedList.print(); 
  //f
  linkedList.add(1,"Brenda");
  //g
  linkedList.print(); 
  //h
  linkedList.remove(2);
  //i
  linkedList.print(); 
  //j
  linkedList.remove(0);
  //k
  linkedList.print(); 
  
  
  return 0;
}

