#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
using namespace std;

class Customer{
public:
    Customer();
    Customer(int office1time, int office2time, int office3time, char office1, char office2, char office3);
    ~Customer();
    int getArrivalTime();
    void setArrivalTime(int t);
    char getNextOffice();
    char getOffice1();
    int getTransactionLength1();
    bool getLastOffice();
    void setLastOffice();
    void updateNextOffice();
    //add getters and setters as needed;
private:
    char nextOffice;
    char office1;
    char office2;
    char office3;
    int transactionLength1;
    int transactionLength2;
    int transactionLength3;
    int arrivalTime;
    int waitTime;
    bool lastOffice;
};

#endif