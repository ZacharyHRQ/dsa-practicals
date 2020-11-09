#include <iostream>
#include <string>
#include "Stack.h"

void addUrl(Stack* stack){
          string url;
          cout << "Enter the url you would like to visit : ";
          cin >> url;
          stack->push(url);
}

void back(Stack* stack , Stack* history){ 
  string url;
  stack->pop(url);
  history->push(url);
}

void forward(Stack* stack, Stack* history){ 
  string url; 
  history->pop(url);
  stack->push(url);
}

int main()
{
    Stack back_stack , history_stack;
    string temp , url;
    Stack* stackPtr = &back_stack;
    Stack* histroyPtr = &history_stack;
    while (temp != "0")
    {
        cout << "[1] Visit URL\n[2] Back\n[3] Forward\n[0] Exit\nYour Choice: ";
        cin >> temp;
        if (temp == "0")
            break;
        if (temp == "1")
          addUrl(stackPtr);
        if (temp == "2")
          back(stackPtr , histroyPtr);
        if (temp == "3")
          forward(stackPtr , histroyPtr);
        back_stack.getTop(url);
        cout << "Your current url : " << url << endl; 
    }
    return 0;
}
