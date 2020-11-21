#include <iostream>
#include <string>
#include <random>
#include "Queue.h"
#include "Customer.h"

using namespace std;

void addCustomer(Queue &queue ,int &qnum){ 
  string name;
  cout << "Enter Customer name: ";
  cin >> name;
  qnum++;
  queue.enqueue(Customer(name,qnum));
}
int main(){
  srand(1);
  int num_of_customers , time_of_simulation , curr_time , qnum , stats;
  Queue queue = Queue();
  time_of_simulation = rand()%100;
  curr_time = 0;
  qnum = 0;
  num_of_customers = 0;
  stats = 0;

  while(curr_time < time_of_simulation){ 
    Customer currCustomer;
    curr_time++;
    if (!queue.isEmpty()){
      queue.dequeue(currCustomer);
      int time_served = currCustomer.getQueueNum();
      cout << "Customer " << currCustomer.getName() << " was served in " << (qnum - time_served ) + 1  << " min(s)" << endl;
      num_of_customers++;
    }
    int k = rand()%3;
    string name;
    switch(k){ 
      case 1: 
        cout << "Enter Customer name: ";
        cin >> name;
        qnum++;
        queue.enqueue(Customer(name,qnum));
        break;
      case 2:
        cout << "Enter Customer name: ";
        cin >> name;
        qnum++;
        queue.enqueue(Customer(name,qnum));
        cout << "Enter Customer name: ";
        cin >> name;
        qnum++;
        queue.enqueue(Customer(name,qnum));
        break;
    }
    stats = curr_time/num_of_customers;
  }
  cout << "In this " << time_of_simulation << "-min period, the average time to be served = " << stats << " mins" << endl;
}

