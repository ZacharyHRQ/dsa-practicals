#include <iostream>
#include "Account.h" 
using namespace std;

class CheckingAccount : public Account {
  private:
    double fee;

  public:
    CheckingAccount();
    CheckingAccount(double,double);
    double getFee();
    void setFee(double);
    virtual void credit(double);
    virtual void debit(double);

};
   

