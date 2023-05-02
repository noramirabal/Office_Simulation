#include "ServiceCenter.h"
#include <iostream>
#include <string>
#include <iostream>


ServiceCenter::ServiceCenter() {

}

//constructor
ServiceCenter::ServiceCenter(int fin, int reg, int cash){
    cout << "FUBAR creating " << fin << ", " << reg << ", " << cash << " windows for the service center." << endl;
    FinAid.addWindows(fin, this);
    Registrar.addWindows(reg, this);
    Cashier.addWindows(cash, this);
    totalStudents = 0;
    clockTick = 0;
}

ServiceCenter::~ServiceCenter(){

}

void ServiceCenter::update()
{
    FinAid.update();
    Registrar.update();
    Cashier.update();
}

void ServiceCenter::enterServiceCenter(Customer c){
    cout << "customer entered the service center" << endl;
    ++totalStudents;
    if (c.getNextOffice() == 'F'){
        cout << "customer needs to go to the finance office" << endl;
        FinAid.enterOffice(c);
    } if (c.getNextOffice() == 'R'){
        cout << "customer needs to go to the registrar office" << endl;
        Registrar.enterOffice(c);
    } else{
        cout << "customer needs to go to the cashier office" << endl;
        Cashier.enterOffice(c);
    }
}

void ServiceCenter::minutePassed(int minutes){
    for (int i = 0; i < minutes; ++i){
        cout << "a minute has passed in the service center" << endl;
        ++clockTick;
        FinAid.minutePassed();
        Registrar.minutePassed();
        Cashier.minutePassed();
    }
}

string ServiceCenter::averageWaitTimes(){
    string finS = to_string(FinAid.meanWaitTime());
    string regS = to_string(Registrar.meanWaitTime());
    string cashS = to_string(Cashier.meanWaitTime());
    return "lol";
}

int ServiceCenter::getStudents() {
    return totalStudents;
}

int ServiceCenter::waitingStudents() {
    return Registrar.getStudentsWaiting() + FinAid.getStudentsWaiting() + Cashier.getStudentsWaiting();
}

int ServiceCenter::getTime() {
    return clockTick;
}
