#include <iostream>
#include "SavingAccount.h"

using namespace std;

SavingAccount::SavingAccount(){}
SavingAccount::SavingAccount(double bal , double rate) : Account(bal)
{
  interestrate = rate;
}
double SavingAccount::getInterestrate(){
  return interestrate;
}

void SavingAccount::setInterestrate(double rate){
  if(rate < 0) cout << "This rate is less than 0";
  else interestrate = rate;
}

double SavingAccount::calculateInterest(){
  return Account::getBalance() * getInterestrate();
}
