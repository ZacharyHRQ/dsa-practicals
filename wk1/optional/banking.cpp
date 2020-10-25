#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"

using namespace std;
int main(){

  vector <Account*> accountVector(3);

  CheckingAccount c1(500 , 2);
  SavingAccount s1(500 , 1.2);

  accountVector[0] = &c1;
  accountVector[1] = &s1;

  int user_input = 0;
  int acc = 0;
  do{
    cout << "What is your account" << endl;
    cin >> acc;
    cout << "1)Debit , 2)Credit , 3)CalculateInterest" << endl;
    cin >> user_input;
    if(user_input == 1) {
      double amt = 0;
      cout << "How much do you want to withdraw ?" << endl; 
      cin >> amt;
      Account* a = accountVector[acc];
      CheckingAccount* cptr = dynamic_cast <CheckingAccount*>(a);
      if(cptr != 0) cptr->debit(amt),cout << cptr->getBalance() << endl;
      else {
        SavingAccount* sptr = dynamic_cast <SavingAccount*>(a);
        sptr->debit(amt);
        sptr->credit(sptr->calculateInterest());
        cout << sptr->getBalance() << endl;
      }
    } 

  }while(user_input != 0);
}

