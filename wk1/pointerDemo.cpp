#include <iostream>
using namespace std;
int main(){

	int value1 = 200000;
	int value2;
	int* ptr;
	ptr = &value1;
	cout << *ptr << endl;
	value2 = *ptr; 
	cout << value2 << endl;
	cout << &value1 << endl;
	cout << ptr << endl;
	ptr = &value2;
	*ptr +=  2000 ;
	cout << value1 << endl;	
	cout << value2 << endl;	

}

