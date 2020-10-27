#include <iostream>
#include "Person.h" 
using namespace std;

Person::Person(){};

void Person::setName(string n){
  name = n;
}

string Person::getName(){
  return name;
}


void Person::setTelNo(string tel){
  telNo = tel;
}

string Person::getTelNo(){
  return telNo;
}

Person::Person(string n , string tel){ 
  Person::setName(n);
  Person::setTelNo(tel);


}



