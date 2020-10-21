#include <iostream>
#include "Employee.h"

using namespace std;
Employee::Employee() {}
Employee::Employee(string f, string l, int s) 
{
	firstName = f;
	lastName = l;
	monthlySalary = s;
}

string Employee::getfirstName() {
	return firstName;
}

void Employee::setfirstName(string f) {
    firstName = f;
}

string Employee::getlastName() {
	return lastName;
}

void Employee::setlastName(string l) {
    lastName = l;
}

int Employee::getSalary() {
	return monthlySalary;
}

void Employee::setSalary(int s) {
    monthlySalary = (monthlySalary > 0)? s : 0;
}



