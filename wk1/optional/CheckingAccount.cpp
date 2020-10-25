#include <iostream>
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount(){}


void CheckingAccount::setFee(double f){
  if (f < 0) cout << "Fees is invalid" << endl;
  else fee  = f;
}


CheckingAccount::CheckingAccount(double bal , double f) : Account(bal){
  setFee(f);
}

double CheckingAccount::getFee(){
  return fee;
}

void CheckingAccount::credit(double amt){
  if(amt < 0) cout << "amount is invalid" << endl;
  else Account::setBalance(Account::getBalance() + amt) , Account::setBalance(Account::getBalance() - fee);
  
}

void CheckingAccount::debit(double amt){
  if(amt < 0) cout << "Debit amount exceeded account balance" << endl;
  else Account::setBalance(Account::getBalance() - amt) , Account::setBalance(Account::getBalance() - fee);
}
