#include <iostream>
#include <string>

#include "Employee.h"
using namespace std;

int main(){
	
	Employee e1("Jack", "Tan", 4600);
	Employee e2("Bob", "Chua", 5000);
	e1.setSalary(e1.getSalary()*1.1),e2.setSalary(e2.getSalary() * 1.1);
	cout << e1.getfirstName() + " " + e1.getlastName() + "'s salary: $" << e1.getSalary() * 12 << endl;
	cout << e2.getfirstName() + " " + e2.getlastName() + "'s salary: $" << e2.getSalary() * 12 << endl;
	return 0;
}

