#include <iostream>
using namespace std;

long power(int a, int n){
  if(a < 0) return 0;
  if(n == 0) return 1; 
  return a*power(a,n-1);
}

void printBackward(int array[] , int n){ 
  if (n > 0){  
    cout << array[n-1] << " "; 
    printBackward(array,n-1);
  }
}

int maxArray(int array[] , int start , int end){ 
 if (end - start == 0) return array[start];
 else {  
   int mid = (start + end ) >> 1;
   //int mid = (start + end ) / 2;
   return max(maxArray(array,start,mid),maxArray(array,mid+1,end));
 }
}

int main(){

  //1

  int base = 0;
  int power_of_base = 2;
  cout << "The result of " << base << " to the power of " << power_of_base << " is ";
  cout << power(base,power_of_base) << endl;
  //2
  int nums[] = {1,2,3,4};
  int n = sizeof(nums)/sizeof(nums[0]);
  printBackward(nums , n);
  cout << endl;
  //3
  cout << maxArray(nums,0,n-1) << endl;
}

