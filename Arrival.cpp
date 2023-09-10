#include "Arrival.h"

/*
 * CLASS: Arrival.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for Arrival class, which is a subclass of Event. The message method prints out the arrival
 * event specific message
 *
 * ---------------------------------------------------------------------------------------
 */

Arrival::Arrival(int id, FoodOrder* type, int arrival, int expiry, int extras, int completion):
Event(id, type, arrival, expiry, extras, completion){
    //arrival events always complete at arrival time
}//constructor

/* ---------------------------------------------------------------------------------------
 *  message(int)
 *
 *  PURPOSE: Print out message for Arrival event with information on the FoodOrder.
 *  PARAMETERS:
 *  int currTime - current time in the simulation for printing out the time message
 *
 *  ---------------------------------------------------------------------------------------
 */

void Arrival::message(int currTime) {
    cout << "TIME: " << currTime << ", FoodOrder " << getID() << " arrives -> Expiry:" << getExpiry() << " - Meal:" <<
    getMeal()->getName() << " - Ingredients:" << getIngredients() << " - Prep.time:" <<
    getPrepTime() << " - Price:" << getPrice() << endl;
}