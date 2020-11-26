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
  queue.enqueue(Customer(name,qnum));
  qnum++;
}
int main(){
  srand(time(0));
  int total_time, time_of_simulation , curr_time ;
  double stats;
  Queue queue;
  //time_of_simulation = 10;
  //time_of_simulation = rand()%100;
  cout << "Enter how long the simulation will take : ";
  cin >> time_of_simulation;
  curr_time = 0;
  total_time = 0;

  for(int i = 0; i <= time_of_simulation; i++){
    curr_time++;
    if (!queue.isEmpty()){
      Customer currCustomer;
      queue.dequeue(currCustomer);
      int time_served = curr_time - currCustomer.getQueueNum();
      total_time += time_served;
      cout << "Customer " << currCustomer.getName() << " was served in " << time_served << " min(s)" << endl;
    }
    int k = rand()%3;
    switch(k){ 
      case 1: 
        addCustomer(queue,curr_time);
        break;
      case 2:
        addCustomer(queue,curr_time);
        addCustomer(queue,curr_time);
        break;
    }
  }
  stats = total_time/time_of_simulation;
  cout << "In this " << time_of_simulation << "-min period, the average time to be served = " << stats << " mins" << endl;
}

