#include <iostream>
#include <string>
#pragma once
using namespace std;

class Person { 

  private:
    string name;
    string telNo;
  public:
    Person();
    Person(string,string);
    void setName(string);
    string getName();
    void setTelNo(string);
    string getTelNo();



};

