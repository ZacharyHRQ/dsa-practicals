#include <iostream>
#pragma once
#include <string>
using namespace std;

class Account {
  private:
    double balance;

  public:
    Account();
    Account(double);
    double getBalance();
    void setBalance(double);
    virtual void credit(double);
    virtual void debit(double);

};
   

