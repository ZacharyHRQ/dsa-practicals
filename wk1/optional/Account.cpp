#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(){}


void Account::setBalance(double bal){
  if (bal < 0) cout << "Balance is invalid" << endl;
  else balance = bal;
}


Account::Account(double bal){
  setBalance(bal);
}

double Account::getBalance(){
  return balance;
}

void Account::credit(double amt){
  if(amt < 0) cout << "amount is invalid" << endl;
  else balance += amt;
}

void Account::debit(double amt){
  if(amt < 0) cout << "Debit amount exceeded account balance" << endl;
  else balance -=  amt;
}
