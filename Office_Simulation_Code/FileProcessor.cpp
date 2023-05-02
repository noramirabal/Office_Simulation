#include "FileProcessor.h"
#include "ServiceCenter.h"
#include "TickData.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

FileProcessor::FileProcessor(string fileName){
    int regWin;
    int cashWin;
    int finWin;
    int numCustomers;
    int clock = 0;
    fstream inputFile(fileName);
    string inputFileName;
    string line;

    inputFileName = fileName;

    //Virtual waiting area
    ListQueue<Customer> waitingArea;
    ServiceCenter SC;

    if (inputFile.is_open()){
    /* getline method gets the line, and returns the line as a string, then
    uses stoi to convert to int value*/
        getline(inputFile, line);
        regWin = stoi(line);

        getline(inputFile, line);
        cashWin = stoi(line);

        getline(inputFile, line);
        finWin = stoi(line);

        SC = ServiceCenter(regWin, cashWin, finWin); //initializing our service center with the appropriate number of windows
        TickData tickArr[100]; //array of tick data

        int tickArrIndex = 0;
        int numCustomers;
        int tickNum;
        int valNum = 1;
        string val;

        int office1Time;
        int office2Time;
        int office3Time;
        char office1;
        char office2;
        char office3;
        

        //iterates through the section of the file with the tick count and all of the students
        while (getline(inputFile, line)){
            //getline(inputFile, line); //tick number 
            tickNum = stoi(line); //turns the tick number into an integer
            getline(inputFile, line); //num of customers
            numCustomers = stoi(line); //turns the num customers into an integer
            //students
            //stores all of the customers data
            for(int i = 0; i < numCustomers; ++i){
                // getline 
                getline(inputFile, line);
                stringstream ss(line);
                while (ss >> val){
                    if (valNum == 1){
                        office1Time = stoi(val);
                    } if (valNum == 2){
                        office2Time = stoi(val);
                    } if (valNum == 3){
                        office3Time = stoi(val);
                    } if (valNum == 4){
                        office1 = val[0];
                    } if (valNum == 5){
                        office2 = val[0];
                    } if (valNum == 6){
                        office3 = val[0];
                    }
                    // increment valnum
                    ++valNum;
                }

                //creates a customer with all of the data
                cout << "adding Customer!" << endl;
                Customer tempCustomer(office1Time, office2Time, office3Time, office1, office2, office3);
                // store arrival tick
                tempCustomer.setArrivalTime(tickNum);
                //loads people into temporary queue before running simulation
                waitingArea.add(tempCustomer);
    
            }
        }
        inputFile.close();
    }
    else {
        cout << "This file could not be read, please try again" << endl;
    }
    
    cout << "Starting Simulation" << endl;
    while (SC.waitingStudents() != 0 || !waitingArea.isEmpty()) {
        // pass tick to service center
        SC.minutePassed(1);
        
        //Check top of waiting area
        //Peek the arrival time of each customer
        //If customer arrival time == current tick, add to queue, else move on
        while (!waitingArea.isEmpty() && waitingArea.peek().getArrivalTime() == SC.getTime()) {
            SC.enterServiceCenter(waitingArea.remove());
        }
        SC.update();
    }
    cout << "Ending Simulation" << endl;
}

FileProcessor::~FileProcessor() {
    
}

