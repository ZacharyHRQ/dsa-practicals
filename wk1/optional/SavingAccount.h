#include <iostream>
#include "Account.h" 

using namespace std;

class SavingAccount : public Account {
  private:
    double interestrate;

  public:
    SavingAccount();
    SavingAccount(double , double);
    double getInterestrate();
    void setInterestrate(double);
    double calculateInterest();

};
   

