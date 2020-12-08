#include <iostream>

using namespace std;

int GCD(int x , int y){
  if (y == 0 ) return x;
  cout << x <<  y << endl;
  return GCD(y,x%y);
}

int iterative_GCD(int x , int y){
  while(y != 0){
    int temp = x;
    x = y;
    y = temp%y;
  }
  cout << x << endl;
  return x;
}


int main(){
  cout << GCD(24,54) << endl;
  cout << iterative_GCD(24,54) << endl;

}

