#include <iostream>
using namespace std;

static int comparisons = 0;
//1
int search(int dataArray[], int arraySize , int target){ 
  for(int i = 0; i<arraySize; i++){
    if(dataArray[i] == target) return i;
    comparisons++; 
   }
   return -1;
} 

//3
int binarySearch (int dataArray[], int arraySize, int target){ 
  int l = 0;
  int r = arraySize;
  while(l <= r){ 
    int mid = l+((r-l)/2); 
    if(dataArray[mid] == target) return mid;
    else if (dataArray[mid] > target)  r=mid-1;
    else l=mid+1;
    comparisons++; 
  }
  return -1;
}

//8
int searchR(int dataArray[],  int arraySize,  int start, int target){ 
  if(start > arraySize) return -1;
  else{ 
    if(dataArray[start] == target)return start;
    else searchR(dataArray,arraySize,start++,target);
  }
}

//9
int binarySearchR (int dataArray[],  int first, int last, int target){ 
  int mid; 
  if(first > last) return -1;
  else{ 
    mid = (first+last)/2
    if(dataArray[mid] == target) return mid;
    else if(dataArray[mid] > target) binarySearchR(dataArray,first,mid-1,target);
    else binarySearchR(dataArray,mid+1,last,target);
  }
}

int main(){

  int dataArray[1000];
  int index = 0;
  for(int i = 2; i < 2001; i+=2){ 
      dataArray[index] = i;
      index++;
  }
  int target = 0; 
  cout << "Enter a number to search for" << endl;
  cin >> target;

  int found = 0;
  if (target > 2000) found = -1;
  else found = search(dataArray,1000,target);

  if (found == -1) cout << "Not found" << endl; 
  else cout << "Found" << endl; 
	cout << "Sequential Search : " << comparisons << endl;

  comparisons = 0;
  target = 0; 
  cout << "Enter a number to search for" << endl;
  cin >> target;

  found = 0;
  if (target > 2000) found = -1;
  else found = binarySearch(dataArray,1000,target);

  if (found == -1) cout << "Not found" << endl; 
  else cout << "Found" << endl; 
	cout << "Binary Search : " << comparisons << endl;


}



