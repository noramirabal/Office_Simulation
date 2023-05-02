#ifndef OFFICE_H
#define OFFICE_H

#include "DblList.h"
#include "ListQueue.h"
#include "Customer.h"
#include "Window.h"
// #include "ServiceCenter.h"
#include <cstdlib>
using namespace std;

// forward declaration
class ServiceCenter;

class Office{
public:
  Office();
  Office(int numWindows);
  ~Office();
  void enterOffice(Customer customerToAdd); //adds a customer to the line
  Customer nextCustomer(); //returns the customer who goes next to the window 
  int windowOpen();
  void minutePassed();
  void addWindows(int numWindows, ServiceCenter* sc);
  int getWaitTime();
  double meanWaitTime();
  int getStudentsWaiting();
  void update();
private:
    ListQueue<Customer> line;
    Window *windowArr;
    int totalCustomers;
    int totalWaitTime;
    int totalWindows;
    int clockTick;
    int numStudentsInLine;
};

#endif