#include "Office.h"
#include "ServiceCenter.h"
#include <iostream>

//default constructor 
Office::Office(){
    clockTick = 0; 
    totalCustomers = 0;
    totalWaitTime = 0;
    numStudentsInLine = 0;

    totalWindows = 0;
    windowArr = new Window[totalWindows];
}

// //overloaded constructor
// Office::Office(int numWindows){
//     clockTick = 0; 
//     totalCustomers = 0;
//     totalWaitTime = 0;
//     numStudentsInLine = 0;

//     totalWindows = numWindows;
//     windowArr = new Window[totalWindows];
//     for (int i = 0; i < totalWindows; ++i){
//         Window *window;
//         window = new Window();
//         windowArr[i] = *window;
//     }
// }

Office::~Office()
{
    // TODO: clean up windows
}

void Office::addWindows(int numWindows, ServiceCenter* sc){
    totalWindows = numWindows;
    windowArr = new Window[totalWindows];
    for (int i = 0; i < totalWindows; ++i){
        windowArr[i] = Window();
        windowArr[i].setServiceCenter(sc);
    }
}

void Office::enterOffice(Customer customerEntered){
    cout << "customer has entered the office and is waiting in line" << endl;
    //changing a customers nextOffice 
    customerEntered.updateNextOffice();
    //adding one to the total customer count for the office
    ++totalCustomers;
    //adding the customer to the back of the line 
    line.add(customerEntered);
    ++numStudentsInLine; //adds 1 to the amount of students in the line
}

void Office::update()
{
    //checking that at least one office window is open and that the line isn't empty
    if (!line.isEmpty()){
        if (windowOpen() != -1){
            cout << "there was a window open in the office" << endl;
            //removes the first person in the line
            Customer nextCustomer = line.remove();
            //removes one from the count of students in line
            --numStudentsInLine; 
            //saves the window which is available
            int openWindow = windowOpen();
            //sends the customer to that window
            windowArr[openWindow].customerEntersWindow(nextCustomer);
        }
        else {
            cout << "there's no window open at the office so a wait time was added to the office total" << endl;
            cout << "fuck you: there are " << line.size() << " customers." << endl;
            ++totalWaitTime;
        }
    }

    cout << "updating " << totalWindows << " windows" << endl;
    for (int i = 0; i < totalWindows; ++i)
        windowArr[i].update();
    
}



int Office::windowOpen(){
    //iterates through all of the windows in the office to check if there is any that is open, the first that it finds open it will return the window position in the array
    for (int i = 0; i < totalWindows; ++i){ //iterates through all windows in an office
        if (!windowArr[i].getOccupied()){ //checks if the window is occupied, enters if it is not
            return i;
        }
    }
    return -1; //returns -1 if all of the windows are occupied
}

Customer Office::nextCustomer(){
    return line.remove();
}

void Office::minutePassed(){
    ++clockTick;
    for (int i = 0; i < totalWindows; ++i){
        windowArr[i].minutePassed();
    }
}

int Office::getWaitTime(){
    return totalWaitTime;
}

double Office::meanWaitTime(){
    if ((totalWaitTime == 0) || (totalCustomers == 0)){
        cout << "0.0" << endl;
        return 0.0;
    }
    cout << totalWaitTime/(double)totalCustomers << endl;
    return totalWaitTime/(double)totalCustomers;
}

int Office::getStudentsWaiting() {
    return numStudentsInLine;
}


