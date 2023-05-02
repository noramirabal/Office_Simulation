#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
#include <cstdlib>
using namespace std;

// forward declaration
class ServiceCenter;

class Window{
public:
  Window();
  ~Window();
  bool getOccupied();
  void customerEntersWindow(Customer c);
  void customerLeavesWindow();
  void minutePassed();
  void customerDone();
  void update();
  void setServiceCenter(ServiceCenter* sc);
private:
  Customer currentCustomer;
  bool occupied;
  //bool firstStudentOfTheMinute;
  int clockTick;
  int taskTime;
  ServiceCenter* sc = nullptr; // do not delete, stack allocated 
};

#endif