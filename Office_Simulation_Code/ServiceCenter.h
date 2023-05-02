#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Window.h"
#include "Customer.h"
#include "Office.h"
#include <cstdlib>
using namespace std;

class ServiceCenter{
public:
  ServiceCenter();
  ServiceCenter(int fin, int reg, int cash);
  ~ServiceCenter();
  void enterServiceCenter(Customer c);
  void minutePassed(int minutes);
  string averageWaitTimes();
  int getStudents();
  int getTime();
  int waitingStudents();
  void update();
private:
  Office FinAid;
  Office Registrar;
  Office Cashier;
  int totalStudents;
  int clockTick;
};

#endif