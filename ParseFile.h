#pragma once

/*
 * CLASS: ParseFile.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for Parse file. Includes all the header files that are necessary to be accessed while the simulation happens.
 *
 * ---------------------------------------------------------------------------------------
 */

#include "Event.h"
#include "Arrival.h"
#include "CompleteService.h"
#include "Prepare.h"
#include "FoodOrder.h"
#include "Burger.h"
#include "Pizza.h"
#include "Stew.h"
#include "Salad.h"
#include "Queue.h"
#include "Stack.h"
#include "PriorityQueue.h"
#include "PQPrice.h"
#include "PQTime.h"

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>

using namespace std;

class ParseFile {
private:
    string fileName;
    int version;
    int currTime;
    double revenue;
    int readOrders;
    int totalOrders;

public:
    ParseFile();
    ParseFile(string, string);
    void read();
    Arrival* parse(string);
    Event* createCopy(Event*);
    Prepare* createPrep(Event*, int);
    CompleteService* createDeparture(Event*, int);
};