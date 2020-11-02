#include <iostream>
#include <string>
#include <algorithm>

#include "List.h"
#include "Person.h"

using namespace std;
int menu(){ 

  int input;
  cout << "---------------- Main Menu -------------------" << endl;
  cout << "[1] List the phone numbers" << endl;
  cout << "[2] Add a new contact" << endl;
  cout << "[3] Remove a contact" << endl;
  cout << "[4] Search for a phone number" << endl;
  cout << "[0] Exit " << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Enter your option : ";
  cin >> input;
  return input;
}


int main(){
  int user_input;
  List personList;
  do { 
    user_input = menu();


    if(user_input == 1) { 

      for(int i = 0; i < personList.getLength(); i++){

        Person person  = personList.get(i);
        cout << "[" << i+1 << "]" << " " << person.getName() << " " << person.getTelNo() << endl;

      }


    }
    else if(user_input == 2){ 
      string name , tel;
      cout << "What is the person's name : ";
      cin >> name;
      transform(name.begin(), name.end(), name.begin(), ::tolower);
      cout << "What is the person's telephone number : ";
      cin >> tel;
      personList.add(Person(name,tel));
    }
    else if(user_input == 3){ 
    
      int n;
      cout << "(Enter any number displayed in option 1)";
      cout << "Which contact would you like to remove ? (Enter any number displayed in option 1) : ";
      cin >> n;
      bool success = personList.remove(n-1);
      if (success) cout << "Contact removed" << endl;
      else cout << "Contact not removed" << endl;

    }
    else if(user_input == 4){ 
    
      string name ;
      cout << "What is the person's name : ";
      cin >> name;
      transform(name.begin(), name.end(), name.begin(), ::tolower);
      Person person = personList.search(name);
      cout << "The contact number of " << person.getName() << " is " << person.getTelNo() << endl;
      
    }

  }while(user_input != 0);

}

