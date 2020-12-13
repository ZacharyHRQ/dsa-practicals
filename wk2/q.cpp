#include <iostream>
#include "List.h" 
using namespace std;
int main(){
  List l; 
  l.add(0);
  l.add(1);
  l.add(2);
  l.add(4);
  l.add(2,3);
  l.print();

}

