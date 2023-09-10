#include "CompleteService.h"

/*
 * CLASS: CompleteService.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for CompleteService class which is a subclass of event. For creating "departure" events, and prints
 * out the final message for the order of the chef completing the order.
 *
 * ---------------------------------------------------------------------------------------
 */

CompleteService::CompleteService(int id, FoodOrder * type, int arrival, int expiry, int extras, int completion):
Event(id, type, arrival, expiry, extras, completion){

    //completionTime is calculated by creation time in simulation + time to make base food + number of extras
} //constructor

/* ---------------------------------------------------------------------------------------
 *  message(int)
 *
 *  PURPOSE: Print out message for CompleteService event with information on the FoodOrder.
 *  PARAMETERS:
 *  int currTime - current time in the simulation for printing out the time message
 *
 *  ---------------------------------------------------------------------------------------
 */

void CompleteService::message(int currTime) {
    cout << "TIME: " << currTime << ", FoodOrder " << getID() << " has been served! Revenue grew by: " << getPrice() << endl;
}

