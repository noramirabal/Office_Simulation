#include "Customer.h"
#include <iostream>

//default constructor 
// Customer::Customer(int office1time, int office2time, int office3time, char office1, char office2, char office3){
//     officeOrder[0] = office1;
//     officeOrder[1] = office2;
//     officeOrder[2] = office3;
//     timeAtOffice[0] = office1time;
//     timeAtOffice[1] = office2time;
//     timeAtOffice[2] = office3time;
//     waitTime = 0;
//     firstOffice = office1;
// }

Customer::Customer(){}

Customer::Customer(int l1, int l2, int l3, char o1, char o2, char o3){
    arrivalTime = 0;
    waitTime = 0;
    lastOffice = false;
    office1 = o1;
    office2 = o2;
    office3 = o3;
    transactionLength1 = l1;
    transactionLength2 = l2;
    transactionLength3 = l3;
}

//destructor
Customer::~Customer(){

}

// void Customer::addWaitTime(){
//     ++waitTime;
//     cout << waitTime << endl;
// }

char Customer::getNextOffice(){
    return nextOffice;
}

int Customer::getArrivalTime(){
    return arrivalTime;
}

void Customer::setArrivalTime(int t) {
    arrivalTime = t;
}

bool Customer::getLastOffice(){
    return lastOffice;
}

int Customer::getTransactionLength1(){
    return transactionLength1;
}

//update to make offices an array later but for now we are hard coding 3 offices always
void Customer::updateNextOffice(){
    if (nextOffice == office1){
        nextOffice = office2;
    } if (nextOffice == office2){
        nextOffice = office3;
    } else{
        nextOffice = 'N';
    }
}