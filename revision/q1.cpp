#include <iostream>
#include "List.h" 
using namespace std;

void f(int& i){ 
  cout << i << endl;
}

int main(){
  List l;
  l.add(1);
  l.add(2);
  l.add(3);
  l.add(4);
  l.add(5);

  l.print();
  cout << endl;
  l.reverseAt(2,4);
  l.print();
  cout << endl;

}

