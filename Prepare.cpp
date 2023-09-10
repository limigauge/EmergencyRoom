#include "Prepare.h"

/*
 * CLASS: Prepare.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for Prepare class (subclass of Event) which prints out messages specific for Prepare events in the simulation.
 *
 * ---------------------------------------------------------------------------------------
 */

Prepare::Prepare(int id, FoodOrder * type, int arrival, int expiry, int extras, int currentTime) :
Event(id, type, arrival, expiry, extras, currentTime){

    //Prepare events are "completed" the moment the are made
}

/* ---------------------------------------------------------------------------------------
 *  message(int)
 *
 *  PURPOSE: Print out a message to indicate the preparation event taking place.
 *  PARAMETERS:
 *  int currTime - current time in the simulation to timestamp the message.

 *  ---------------------------------------------------------------------------------------
 */

void Prepare::message(int currTime) {
    cout << "TIME: " << currTime << ", FoodOrder " << getID() << " is getting prepared by the chef!" << endl;
}
