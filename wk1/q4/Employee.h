#include <iostream>
#include <string>
using namespace std;

class Employee {
	private:
		string firstName;
		string lastName;
		int monthlySalary;
	public:
		Employee();
		Employee(string, string, int);
		string getfirstName();
		void setfirstName(string);
		string getlastName();
		void setlastName(string);
		int getSalary();
		void setSalary(int);
}; 
