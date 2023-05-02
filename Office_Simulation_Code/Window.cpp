#include "Window.h"
#include "ServiceCenter.h"
#include <iostream>

using namespace std;


Window::Window(){
    occupied = false;
    clockTick = 0;
    taskTime = 0;
    //firstStudentOfTheMinute = true;
}

Window::~Window(){
}


void Window::customerEntersWindow(Customer c){
    cout << "the customer has entered the window" << endl;
    currentCustomer = c;
    taskTime = currentCustomer.getTransactionLength1() + clockTick;
    occupied = true;
}

void Window::customerDone(){
    if (taskTime > clockTick){
        cout << "the customer hasn't finished their task" << endl;
    } else{
        cout << "the customer finished their task" << endl;
        customerLeavesWindow();
    }
}

void Window::update()
{
    cout << "window fuck you update" << endl; 
    customerDone();
}

void Window::customerLeavesWindow(){
    cout << "the customer has left the window" << endl;
    //either sends the customer back to the service center or the customer is done
    if (currentCustomer.getNextOffice() != 'N'){
        cout << "the customer has more tasks to complete" << endl;
        //send the customer back to the service center
        sc->enterServiceCenter(currentCustomer);
        // set current customer to null.
        currentCustomer = Customer();
    } else{
        cout << "the customer is done with their task" << endl;
    }
    taskTime = 0;
    occupied = false;
}

void Window::minutePassed(){
    ++clockTick;
    //firstStudentOfTheMinute = true;
}

bool Window::getOccupied(){
    return occupied;
}

void Window::setServiceCenter(ServiceCenter* sc) {
    this->sc = sc;
}





