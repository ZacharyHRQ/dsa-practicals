#include <iostream>
using namespace std;
int main()
{
	int digit;
	int counter = 10000;
	cout << "Input a 5 digit integer :";
	cin >> digit;
	while (input > 0) {
		cout << digit/counter << "   ";
		digit = digit % counter;
		counter /= 10;
	}
}
