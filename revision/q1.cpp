#include <iostream>
#include "List.h"
using namespace std;
int main(){ 

  List list;
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);

  list.sortedInsert(5);
  //list.sortedInsert(0);

  list.print();
  


}

