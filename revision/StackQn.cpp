#include <iostream>
#include "List.h"

using namespace std;


void countPosNeg(int *pos , int *neg){ 
  for(int i : arr){ 
    if( i < 0) *neg++;
    else *pos++;
  }
  cout << *pos << " " << *neg << endl;
}


int main(){

  
}

