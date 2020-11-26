#include <iostream>
#include "Dictionary.h"
using namespace std;
int main(){
  Dictionary phoneBook;

  phoneBook.add("Pamela", "64606722");
  phoneBook.add("PohSeng", "64608687");
  phoneBook.add("Wesley", "64607237");
  phoneBook.add("WeeChong", "64606854");

  cout << "Print" << endl;
  phoneBook.print();
  cout << "\n"; 

  phoneBook.add("Eugene", "64608206");
  phoneBook.add("Saiful", "64608256");
  
  cout << "Print" << endl;
  phoneBook.print();
  cout << "\n"; 

  phoneBook.add("PohSeng", "12345678");

  phoneBook.remove("Eugene");

  cout << "Print" << endl;
  phoneBook.print();
  cout << "\n"; 


  

}

